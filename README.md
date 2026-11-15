<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/get_next_linem.png" width="125" alt="Get_Next_Line 42 project badge" /></a>

# Get_Next_Line

**Buffered file reading in C**

<img src="https://img.shields.io/badge/42%20School-Project-0F766E?style=flat-square" alt="42 School project" />

</div>

---

## 🔎 Overview

**Get_next_line** is an individual project at 42 School that implements a function to read a file, returning one line at a time from a file descriptor. This project challenges your ability to manage memory, handle buffers, and work with file descriptors efficiently. The bonus part extends the functionality by allowing multiple file descriptors to be read concurrently.

The goal? Deliver a robust and efficient function that behaves similarly to the standard I/O functions while adhering to the 42 School coding standards.

---

## ✨ Key Features

### Core Functionality
- **Line-by-Line Reading**  
  Reads one line at a time from a given file descriptor.
  
- **Buffer Management**  
  Efficiently handles input buffering to optimize read operations.

- **Memory Handling**  
  Dynamically allocates memory to store lines and avoids memory leaks.

### Bonus Features
- **Multi-file Descriptor Support**  
  Capable of handling multiple file descriptors concurrently, ensuring that each file maintains its own reading state.
  
- **Linked List Implementation**  
  Bonus implementation leverages linked lists to dynamically manage multiple buffers and file descriptors.

### Core Files
- [`get_next_line.c`](https://github.com/doooriian/Get_Next_Line/blob/main/get_next_line.c) — Implements the core logic for reading and returning a single line.
- [`get_next_line_utils.c`](https://github.com/doooriian/Get_next_line/blob/main/get_next_line_utils.c) — Contains helper functions for memory management and string manipulations.
- [`get_next_line_bonus.c`](https://github.com/doooriian/Get_next_line/blob/main/get_next_line_bonus.c) — Bonus file handling multiple file descriptors using linked lists.

---

## 🛠️ Technologies Used
- **[C](https://devdocs.io/c/)** — Core programming language.
- **[Makefile](https://www.gnu.org/software/make/manual/make.html)** — Build automation tool.

---

## 🚀 How to Build and Run

1. Clone repository
    ```bash
    git clone git@github.com:doooriian/Get_next_line.git
    ```

2. To use the library in your code, `#include` the following header
    ```c
    #include "get_next_line.h"


3. Follow these instructions
```bash
### Build and Run

Since the project contains only a function, you can test it by creating a simple `main.c` file that calls `get_next_line`
For example, here’s a minimal test program:

```c
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}


```
## 🧪 Testing

This project was tested using custom test cases to ensure robust performance and efficient memory management. The bonus functionality was extensively validated to handle multiple file descriptors simultaneously, using linked lists to manage dynamic buffers.


## 📬 Contact

Feel free to reach out or contribute to this project via [GitHub](https://github.com/doooriian)!
