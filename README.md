Process Management

## Description

This project covers the exercises from Lab 5 of the Operating Systems course (CSE233). It demonstrates process creation, background processing, process control (stop/continue), and the roles of the Linker and Loader.

## Files

- **Exercise 1**: `process_creation.c` - Demonstrates `fork()` system call.
- **Exercise 2**: `exercise2.c` - C program demonstrating background process creation.
- **Exercise 3**: `exercise3.c` - C program demonstrating stopping a process with `SIGKILL`.
- **Exercise 4**: `exercise4.c` - C program demonstrating pausing (`SIGSTOP`) and resuming (`SIGCONT`) a process.
- **Exercise 5**: `file1.c`, `file2.c` - Demonstrates linking two C files.
- **Exercise 6**: `simple_program.c` - Demonstrates the role of the loader and `ldd`.
- `answers.txt`: Explanations of the exercises, Linker, and Loader.
- `Makefile`: Script to compile the C programs.

## Installation and Usage

### Prerequisites

- GCC Compiler
- Make (optional)
- Linux environment (WSL on Windows or native Linux) for shell scripts and system calls.

### Compilation

To compile the C programs, run:

```bash
make
```

Or compile individually:

```bash
gcc process_creation.c -o process_creation
gcc file1.c file2.c -o output_program
gcc simple_program.c -o simple_program
```

### Running

**C Programs:**
```bash
./process_creation
./exercise2
./exercise3
./exercise4
./output_program
./simple_program
```

**Note:** These programs use POSIX system calls (`fork`, `kill`, `sleep`) and must be run in a Linux/Unix environment (like WSL).

## License

[MIT](LICENSE)

