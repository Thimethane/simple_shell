0x16. C - Simple Shell
Project to be done in teams of 2 people (Timothee RINGUYENEZA)
General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?
Tasks
0. Betty would be proud
  Write a beautiful code that passes the Betty checks
1. Simple shell 0.1
  Write a UNIX command line interpreter.
2. Simple shell 0.2
  Simple shell 0.1 +
     Handle command lines with arguments
3. Simple shell 0.3
  Simple shell 0.2 +
4. Simple shell 0.4
  Simple shell 0.3 +
  Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
5. Simple shell 1.0
  Simple shell 0.4 +
Implement the env built-in, that prints the current environment
6. Simple shell 0.1.1
  Simple shell 0.1 +
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
7. Simple shell 0.2.1
  Simple shell 0.2 +
You are not allowed to use strtok
8. Simple shell 0.4.1
  Simple shell 0.4 +
handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell
9. setenv, unsetenv
  Simple shell 1.0 +
10. cd
  Simple shell 1.0 +
Implement the builtin command cd:
11. ;
Simple shell 1.0 +
Handle the commands separator ;
