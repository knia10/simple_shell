# simple_shell
## _Description_

In this project we try to replicate a command-line interpreter or shell that provides a command line. Which can operate both an interactive and a non-interactive mode. 

## _C Language standard functions and system calls utilized_

access, execve, exit, fork, free, getcwd, isatty, malloc, read, write, signal, wait. 

## _Brief synopsis_

All files in this repository are designed to compile with GNU compiler in the Linux environment from  _Ubuntu 20.04 LTS_. When compiled, the executable program replicates a "shell" or command line interpreter, which is a user interface used for access to an operating system's services. This shell has a set of custom built-in commands, and also integrates with other commands located in the system's PATH. Output and functionality from commands is designed to replicate output from the shell and other commands. 

## _Usage_

### Compile with: 
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Execution
- interactive mode: *$ ./hsh*
- non-interactive mode: *echo "ls -la" | ./hsh*
