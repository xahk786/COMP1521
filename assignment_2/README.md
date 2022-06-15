# Assignment 2: shuck, A Simple Shell  
**Pw:** cseass2

- **Final Assignment mark:** 97/100
    - **Automated Testing:** 78.0/80
    - **Style** : 19/20

#  Introduction

Shells can do a lot more than just reading command lines and executing them. They can keep a history of previous commands to make it easy to re-execute them. They can also allow users to capture the output of a command, by redirecting its input or output from or into a file. And, importantly on Unix/Linux, they allow users to build a pipeline of commands to achieve powerful effects without having to write a dedicated program. 

# shuck.c: The Assignment

Your task in this assignment is to write shuck, a small but useful subset of the core functionality typical of a Unix/Linux shell.

## **Subset 0: cd and pwd** 
For this subset, you will add code to shuck.c — in particular, the function execute_command — to implement the shell built-in commands cd (change directory), and pwd (print working directory).

## **Subset 1: Running Commands** 
For this subset, you will add code to shuck.c — in particular, to the function execute_command — you will to modify shuck.c — in particular, the function execute_command — to execute commands which are not built-in.

Execute_command takes three arguments. Of interest to us are the first two: words, described elsewhere; and path a list of directories to search for the corresponding executable file, as an array of strings. The first word of the command specifies a program to run. Based on these arguments, you need to find an executable file corresponding to the command and execute it.

## **Subset 2: Making history** 
For this subset, you will need to modify shuck.c :
- to save every command run to the file $HOME/.shuck_history;
- to implement a built-in command history n which prints the last n commands, or, if n is not specified, 10; and
- to implement a built-in command ! n which prints the nth command and then executes it, or, if n is not specified, the last command.

## **Subset 3: Filename Expansion (Globbing)**
For this subset, you will need to modify shuck.c to support filename expansion, sometimes referred to as globbing.

- If any of the characters '*', '?', '[', or '~' appear in a word, that word should be taken as a pattern, and should be replaced by all of the words matching that pattern using the glob library function; or, if there are no matches, use the pattern-word unchanged. This may result in the word list becoming longer than it initially was.

## **Subset 4: Input/Output Redirection**

For this subset, you will need to modify shuck.c to support input and output redirections:

- If the first two tokens of the command line are <, and a filename, the command should be executed with its standard input connected to the specified file. If the file does not exist, or is not readable, an error message should be printed instead.

- If the last two words of the command line are >, and a filename, the command should be executed with its standard output connected to the specified file. If the file is not writable, an error message should be printed instead. If the file exists, it should be over-written.

- If the last three words of the command line are >, >, and a filename, the command should be executed with its standard output connected to the specified file such that its output is appended to the file, rather than the file being overwritten. If the file is not writable, an error message should be printed instead.

- Additionally, an error message should be printed
    - if > or < appear anywhere elsewhere on the command-line;
    - if no command is specified to redirect; or
    - if a builtin command is specified with I/O redirection.

## **Subset 5: Pipes**
For this subset, you will need to modify shuck.c to support pipelines, which, within a command line, connect the standard output of one command to the standard input of the next.

- If a '|' appears between two commands, the standard output of the first command should be connected to the standard input of the second command.
