# simple_shell 🪐

## Flowchart
To understand how our function works, check the flowchart.
![Flowchart](https://github.com/knia10/simple_shell/blob/master/Flowchart/Flowchart_Simple_Shell.png)
## _Description_ ⭐

In this project we try to replicate a command-line interpreter or shell that provides a command line. Which can operate both an interactive and a non-interactive mode. 

## _C Language standard functions and system calls utilized_ 🌪
`access`, `execve`, `exit`, `fork`, `getcwd`, `isatty`, `malloc`,`read`, `write`, `signal`, `wait`.
 
## _Brief synopsis_

All files in this repository are designed to compile with GNU compiler in the Linux environment from  _Ubuntu 20.04 LTS_. When compiled, the executable program replicates a "shell" or command line interpreter, which is a user interface used for access to an operating system's services. This shell has a set of custom built-in commands, and also integrates with other commands located in the system's PATH. Output and functionality from commands is designed to replicate output from the shell and other commands. You can find more information about the subject following the next link: https://www.linkedin.com/pulse/what-happens-when-u-type-ls-l-c-shell-eylen-manuela-s%25C3%25A1nchez-chica

## _Usage_

### Installation 🕹
- Clone the Repository:
$ `git clone https://github.com/knia10/simple_shell.git`
### Compile with: 🗝 
$ `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
### Execution 🏹
- Interactive mode: *$ `./hsh*`
- Non-interactive mode: $ `*echo "ls -la" | ./hsh*`

## List of Functions 📁

|File | Description |
| ------ | ------ |
| _strcat| [Concatenate two strings][PlDb] |
| _strcmp| [Compare two strings][PlGh] |
| _strcpy| [Copies the string pointed to by src,including the terminating null byte (\0), to the buffer pointed to by dest][PlGd] |
| _strdup | [Returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter][PlOd] |
| _string_tok | [Splits a str into substrings separated by delm][PlMe] |
| f_exit | [Cause process termination][PlGa] |
| _getline | [Stores into malloced buffer the user's command into shell][PlGa] |
| _which | [Fleshes out command by appending it to a matching PATH directory][PlGa] |
| _execute | [Execute command typed into shell][PlGa] |
| _realloc | [Allocate memory and set all values to 0][PlGa] |

### Examples  🍃
- Interactive mode: 
$ `./hsh`
($) `/bin/ls`
hsh main.c shell.c
($)
($) `exit`
$
- Non-interactive mode:
$ `echo "/bin/ls" | ./hsh`
hsh main.c shell.c test_ls_2
$
$ `cat test_ls_2`
/bin/ls
/bin/ls
$
$ `cat test_ls_2 | ./hsh`
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

### Authors ✒️

* Estefania Ruiz Acevedo - [knia10](https://github.com/knia10)
* Eylen Sanchez - [EylenS](https://github.com/EylenS)
* Mayi Cadavid - [mayii527](https://github.com/mayii527)

