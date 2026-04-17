# MyShell

A Unix shell implemented in C from scratch.

## Features

- Command execution via fork/exec
- Built-in commands: `cd`, `exit`, `help`, `history`
- I/O Redirection (`>`, `<`, `>>`)
- Pipe support (`|`)
- Command history
- Signal handling (Ctrl+C, Ctrl+Z)
- Colorful prompt

## Build

```bash
make

Usage
./myshell

Examples

myshell> ls -la
myshell> ls | grep .c
myshell> ls > output.txt
myshell> cat < output.txt
myshell> history

Tech Stack
	Language: C
	System calls: fork, exec, pipe, dup2, waitpid
	OS: Unix/Linux/macOS
