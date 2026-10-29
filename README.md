# get_next_line

A project from the 42 curriculum. The goal of this project is to write a function that returns a line read from a file descriptor.

By completing this project, you will learn how to read data from files, manage memory allocation dynamically, and understand the use of static variables in C.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Compilation and Usage

### 1. Requirements

The function needs to be compiled with a specific flag to define the `BUFFER_SIZE`. This size determines how many bytes the `read()` function will process at a time. If not specified during compilation, it is usually defined in the header file.

### 2. Use in your project

Include the header in your C files:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile your program together with the `get_next_line` files:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_program
./gnl_program
```

## Structure

* `get_next_line.c` - Contains the core logic for the function, including reading from the file, extracting the current line, and storing the remaining characters for the next call (functions like `ft_readbuff`, `ft_getline`, and `ft_restofline`).

* `get_next_line_utils.c` - Helper file containing standard string manipulation functions required for the project (such as `ft_strlen`, `ft_strjoin`, etc.).

* `get_next_line.h` - The header file containing all necessary includes and function prototypes.

## Author

* **jschmunk** - *42 Student*