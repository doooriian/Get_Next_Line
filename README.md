<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/get_next_linem.png" alt="Get_Next_Line 42 badge" width="125" /></a>

# Get_Next_Line

**42 School · 📖 Software engineering project**

<img src="https://img.shields.io/badge/42_Project-C%20%7C%20File%20I%2FO-0F766E?style=flat-square" alt="Get_Next_Line technology" />
<img src="https://img.shields.io/badge/Documentation-Project_Overview-334155?style=flat-square" alt="Project documentation" />

</div>

---


---

## 🔎 Overview

A line-oriented reader for file descriptors, designed to return one line per call while keeping unread data across calls.


---

## ✨ Features

- Incrementally read input using a configurable `BUFFER_SIZE`
- Return dynamically allocated lines to the caller
- Preserve leftover content between successive calls
- Provide a separate bonus implementation for multiple file descriptors


---

## 🧩 Technical approach

The mandatory and bonus versions are kept in separate source files. The caller is responsible for freeing each returned line.

> **Tech stack** · C · `read` · File descriptors · Buffering.


---

## 🚀 Build and usage

```bash
git clone https://github.com/doooriian/Get_Next_Line.git
cd Get_Next_Line
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
```

Include `get_next_line.h` and compile these sources with your application. For the bonus implementation, use `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, and `get_next_line_bonus.h` instead.


---

## 🧪 Verification

Review the output with representative inputs and edge cases. No automated CI test suite is included in this repository; build and behaviour should be verified in a compatible local environment.


---

## ⚠️ Notes and limitations

This repository has no Makefile or standalone executable. It provides source files to integrate into a C program.

---

<div align="center">

<sub>Part of the <a href="https://42.fr/">42 curriculum</a> · <a href="https://github.com/doooriian">Back to my GitHub profile</a></sub>

</div>
