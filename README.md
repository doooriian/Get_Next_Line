# Get_Next_Line

> **42 School project** · C · File descriptors and buffered I/O

A line-oriented reader for file descriptors, designed to return one line per call while keeping unread data across calls.

## Overview

A line-oriented reader for file descriptors, designed to return one line per call while keeping unread data across calls.

## Features

- Incrementally read input using a configurable `BUFFER_SIZE`
- Return dynamically allocated lines to the caller
- Preserve leftover content between successive calls
- Provide a separate bonus implementation for multiple file descriptors

## Technical approach

The mandatory and bonus versions are kept in separate source files. The caller is responsible for freeing each returned line.

**Stack:** C · `read` · File descriptors · Buffering.

## Build and usage

```bash
git clone https://github.com/doooriian/Get_Next_Line.git
cd Get_Next_Line
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
```

Include `get_next_line.h` and compile these sources with your application. For the bonus implementation, use `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, and `get_next_line_bonus.h` instead.

## Verification

Review the output with representative inputs and edge cases. No automated CI test suite is included in this repository; build and behaviour should be verified in a compatible local environment.

## Notes and limitations

This repository has no Makefile or standalone executable. It provides source files to integrate into a C program.

---

Part of the [42 curriculum](https://42.fr/). Explore the other projects on [my GitHub profile](https://github.com/doooriian).
