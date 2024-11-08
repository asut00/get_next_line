# get_next_line

Welcome to **get_next_line**! 📜  
This project is all about creating a function that reads a line from a file descriptor in C. **get_next_line** efficiently handles reading files of any size, line by line, without using any pre-built functions that automatically handle line breaks.

## Project Description

The **get_next_line** project, part of the [42 School](https://42.fr/) curriculum, focuses on building a custom function that reads from a file descriptor and returns one line at a time. This function replicates the behavior of a standard line-reading function, but with strict constraints that make it more challenging to handle memory and buffering efficiently.

## Objective

The purpose of **get_next_line** is to:
- Develop a function that reads from any file descriptor, including files and standard input.
- Return each line of the file (or input) until the end is reached.
- Manage a buffer to handle large files or inputs efficiently without memory leaks.

The project strengthens skills in dynamic memory management, string manipulation, and working with buffers.

## Function Prototype

The prototype for **get_next_line** is as follows:
```c
char *get_next_line(int fd);
```

- **fd**: The file descriptor to read from.
- **Return Value**: Returns the next line from the file descriptor, or `NULL` when there are no more lines to read.

## Key Features

- **Buffer Management**: Uses a buffer to store read characters, handling both short and long lines seamlessly.
- **Dynamic Memory Allocation**: Manages memory dynamically for each line, ensuring no leaks occur during usage.
- **Reusable Across Descriptors**: The function can handle multiple descriptors, making it versatile for various input sources.

## Installation

To add **get_next_line** to your project:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/get_next_line.git
   cd get_next_line
   ```

2. **Compile the function**:
   Add the source files `get_next_line.c` and `get_next_line_utils.c` to your project and compile as follows:
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test
   ```

   Replace `BUFFER_SIZE` with the buffer size you prefer (e.g., 42, 1024). 

## Usage

Here’s how to use **get_next_line** in a sample program:

```c
#include <fcntl.h>
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

In this example, **get_next_line** reads each line from `example.txt` and prints it to the standard output.

## Buffer Size

The `BUFFER_SIZE` is an important variable that determines how many bytes **get_next_line** reads at a time. Adjusting this value can affect the function’s performance:
- **Small Buffer**: Less memory usage but potentially slower.
- **Large Buffer**: Faster for large files, though it may consume more memory.

Experiment with different values to find the optimal balance for your use case.

## Limitations and Edge Cases

While **get_next_line** is a powerful tool, there are a few considerations:
- **End of File (EOF)**: The function returns `NULL` when all lines have been read or if an error occurs.
- **Empty Lines**: It correctly handles empty lines within the file.
- **Memory Leaks**: Ensure each returned line is freed after use to prevent memory leaks.

## Author

- GitHub: [@asut00](https://github.com/asut00)  
- 42 Intra: `asuteau`
