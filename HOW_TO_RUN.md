# How to Run Lab 5 Exercises on Ubuntu

This guide provides step-by-step instructions to compile and run all 6 exercises from Lab 5 on Ubuntu.

## Prerequisites

Install build tools if not already installed:

```bash
sudo apt update
sudo apt install build-essential -y
```

Verify GCC is installed:

```bash
gcc --version
```

## Build All Programs

Navigate to the project folder in terminal and run:

```bash
make
```

This will compile all exercises and create the following executables:
- `process_creation`
- `exercise2`
- `exercise3`
- `exercise4`
- `output_program`
- `simple_program`

To clean up compiled files:

```bash
make clean
```

## Running Each Exercise

### Exercise 1: Process Creation with fork()

```bash
./process_creation 2>&1 | tee run_ex1.txt
```

**Expected Output:** Parent and child processes print their PIDs.

---

### Exercise 2: Background Process

```bash
./exercise2 2>&1 | tee run_ex2.txt
```

Or run in background:

```bash
./exercise2 &> run_ex2.txt &
tail -f run_ex2.txt
```

**Expected Output:** Parent exits immediately while child sleeps for 10 seconds in the background.

---

### Exercise 3: Stopping a Process with SIGKILL

```bash
./exercise3 2>&1 | tee run_ex3.txt
```

**Expected Output:** Parent starts child, waits 2 seconds, sends SIGKILL to terminate it, then confirms termination.

---

### Exercise 4: Pause and Resume Process (SIGSTOP/SIGCONT)

```bash
./exercise4 2>&1 | tee run_ex4.txt
```

**Expected Output:** Child prints messages repeatedly. Parent pauses it with SIGSTOP, waits 5 seconds (child stops printing), then resumes with SIGCONT (child resumes printing), and finally kills it.

---

### Exercise 5: Role of the Linker

```bash
./output_program 2>&1 | tee run_ex5.txt
```

**Expected Output:** Prints "Hello from file1!" demonstrating successful linking of `file1.c` and `file2.c`.

---

### Exercise 6: Role of the Loader (Dynamic Libraries)

Run the program:

```bash
./simple_program 2>&1 | tee run_ex6.txt
```

List dynamic libraries:

```bash
ldd ./simple_program | tee run_ex6_ldd.txt
```

**Expected Output:** 
- `simple_program` prints its message
- `ldd` shows shared libraries like `libc.so.6` and the dynamic linker

---

## Helpful Commands

Check running processes:

```bash
ps aux | grep exercise
```

View process tree:

```bash
pstree -p | less
```

Monitor child processes:

```bash
watch -n 1 'ps aux | grep exercise'
```

---

## Capturing Screenshots and Logs

### Save Terminal Output

The commands above use `tee` to save output to `.txt` files:
- `run_ex1.txt`
- `run_ex2.txt`
- `run_ex3.txt`
- `run_ex4.txt`
- `run_ex5.txt`
- `run_ex6.txt`
- `run_ex6_ldd.txt`

### Take Screenshots

**Using GNOME Screenshot:**

```bash
sudo apt install gnome-screenshot
gnome-screenshot -w -f screenshot_compile.png
gnome-screenshot -w -f screenshot_run.png
```

Or press `PrtSc` key to capture screen.

### Organize Files

Create a screenshots folder:

```bash
mkdir -p screenshots
mv run_ex*.txt screenshots/
mv screenshot*.png screenshots/
```

---

## Git Commit and Push to GitHub

Add all files:

```bash
git add .
```

Commit changes:

```bash
git commit -m "Lab 5: Add exercises 1-6 with build and run logs"
```

Push to GitHub (first time setup):

```bash
git remote add origin https://github.com/<YOUR-USERNAME>/<REPO-NAME>.git
git push -u origin main
```

For subsequent pushes:

```bash
git push origin main
```

---

## Troubleshooting

### Compilation Errors

If `make` fails, try compiling individual files:

```bash
gcc -Wall -o process_creation process_creation.c
gcc -Wall -o exercise2 exercise2.c
gcc -Wall -o exercise3 exercise3.c
gcc -Wall -o exercise4 exercise4.c
gcc -Wall file1.c file2.c -o output_program
gcc -Wall -o simple_program simple_program.c
```

### Permission Denied

Make executables runnable:

```bash
chmod +x process_creation exercise2 exercise3 exercise4 output_program simple_program
```

### GCC Not Found

Install build tools:

```bash
sudo apt install build-essential
```

---

## Assignment Deliverables Checklist

- [ ] All 6 C programs compiled successfully
- [ ] `answers.txt` with explanations completed
- [ ] `README.md` file present
- [ ] `Makefile` working
- [ ] `LICENSE` file included
- [ ] Screenshots of compilation (`make` output)
- [ ] Screenshots of running each program
- [ ] Terminal output logs saved
- [ ] Public GitHub repository created
- [ ] All files pushed to GitHub
- [ ] GitHub repository link ready for submission

---

## Quick Run All (Optional)

To run all exercises in sequence and save outputs:

```bash
echo "=== Exercise 1 ===" && ./process_creation 2>&1 | tee run_ex1.txt
echo "=== Exercise 2 ===" && ./exercise2 2>&1 | tee run_ex2.txt
echo "=== Exercise 3 ===" && ./exercise3 2>&1 | tee run_ex3.txt
echo "=== Exercise 4 ===" && ./exercise4 2>&1 | tee run_ex4.txt
echo "=== Exercise 5 ===" && ./output_program 2>&1 | tee run_ex5.txt
echo "=== Exercise 6 ===" && ./simple_program 2>&1 | tee run_ex6.txt
echo "=== Exercise 6 (ldd) ===" && ldd ./simple_program | tee run_ex6_ldd.txt
```
