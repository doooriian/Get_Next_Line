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

Clone the repository:

```bash
git clone https://github.com/doooriian/Get_Next_Line.git
cd Get_Next_Line
```

This project provides a function, not a standalone executable or a Makefile. Compile the mandatory source files with your test program:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    main.c get_next_line.c get_next_line_utils.c -o gnl_test
```

Here is an example `main.c` (create a text file named `file.txt` in the same directory):

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

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

For the bonus version, compile `get_next_line_bonus.c` and `get_next_line_utils_bonus.c` and include `get_next_line_bonus.h`. The bonus implementation supports reading from multiple file descriptors.

---

## 🧪 Testing

This project was tested using custom test cases to ensure robust performance and efficient memory management. The bonus functionality was extensively validated to handle multiple file descriptors simultaneously, using linked lists to manage dynamic buffers.


## 📬 Contact

Feel free to reach out or contribute to this project via [GitHub](https://github.com/doooriian)!
