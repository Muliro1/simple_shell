
## Simple_shell Project

This is a project created by [Abeeb Raheem](https://github.com/belovetech) and [Ogunbanjo Nimota Busayo](https://github.com/Nimbusshub). This project recreates the shell which is the Linux command line interpreter in its simplest form. It provides an interface between the user and the kernel and executes programs.

The "Simple_shell" is a program that can be compiled and launched from the command line, where its main function is to execute commands read from the standard input. It contains some of the basic features and functions found in the various shell programs like Kernel commands and builtin commands.

## Quick Start

1. Git clone this respository to your local directory.

       $ git clone https://github.com/belovetech/simple_shell.git
  
2. Compile the program.

       $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
       
3. Now execute the shell.
      
       $ ./hsh
       
## Builtin Commands

This shell supports the next builtin commands:

    cd - change directory

    env - list the current environment variables

    exit - exit the shell
    
    help - show help for a builtin command
    
    pwd - Print the absolute pathname of the current working directory
    
    unsetenv - Remove an environment variable

## Delimit and comment commands

	; -  The semicolon. command separator that allows to run a command on a single line placing the semicolon between
       each command.
	
	# - The command number. Allows a word beginning with # and all remaining characters on that line to be ignored.

## Manual

To see the manual run:

    $ man ./man_1_simple_shell
    
Example:
    	
	man(1)                                  Manual page for Simple_Shell           			man(1)                                

	NAME
       	Simple_Shell - Command language interpreter

	SYNOPSIS
       	./hsh

	DESCRIPTION
       	Command language interpreter that executes commands read from the standard input or from a file.

	INVOCATION
       	An  interactive  shell is one started without non-option arguments, just running ./hsh. 
	Otherwise, when is started non-interactively, to run a shell script, for example, the 
	shell reads and execute the next command echo "pwd" | ./hsh.
	
							.  .  .


## Files

Brief description of every file in this repository.
	
| File | Description |
| ------------- | ------------- |
| _atoi.c | function that gets sign and numbers of string |
| _calloc.c | function that allocates memory for an array |
| _change.c | functions that change the OLDPWD and PWD environment variables |
| _display_help.c | functions that reads all builtins text files and prints it to POSIX stdout |
| _envir.c | functions to print the environment variables and create a copy of env |
| _errors.c | functions with the error message for each builtin |
| _forky.c | program that creates process and execute |
| _gethome.c | funtion to get the environment variable HOME |
| _getline.c | functions to read what the user writes |
| _iscd.c | functions to change the current directory of the process. |
| _isexit.c | functions that finds if line input is exit therefore process termination |
| _ishelp.c | functions to print the help of each builtin |
| _noargv.c | function to give shell form without filename as input |
| _realloc.c | function to change the size and copy the content |
| _realloc2.c | function to change the size and copy the content special case |
| _signal.c | function to handle SIGINT signal |
| _str_concat.c | function to create an array using malloc |
| _strlen.c | function that returns the length of a string |
| _unsetenv.c | functions to remove an environment variable |
| _strtoky.c | functions to cut a string into tokens depending of the delimit|
| _writerr.c | functions to print the error for each builtin |
| _yesargv.c | function to give shell form with filename as input |
| checkbin.c | functions to check if commands exist in the path |
| free_grid.c | function to free a matrix |
| man_1_simple_shell | manual of simple_shell |
| parsing.c | functions that create an array of pointers depending of the delimit characters |
| shell.h | header file with all thr function prototypes |
| startshell.c | main function that stars the shell (shell skeleton) |

## Examples
Some examples for builtins after execute ./hsh

cd:

	#cisfun$ pwd
	/home/vagrant/simple_shell
	#cisfun$ cd
	#cisfun$ pwd
	/home/vagrant
	#cisfun$
	
cd error:

	#cisfun$ cd hola
	./hsh: 1: cd: can't cd to hola
	#cisfun$

exit:

	#cisfun$ exit 123
	vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo $?
	123
	
exit error:

	#cisfun$ exit hola
	./hsh: 2: exit: Illegal number: hola
	#cisfun$

help:

	#cisfun$ help exit
	exit: exit [n]
    	Exit the shell.

    	Exits the shell with a status of N.  If N is omitted, the exit status
    	is that of the last command executed.
	#cisfun$

help error:

	#cisfun$ help hola
	./hsh: 4: help: no help topics match 'hola'. Try 'help help' or 'man -k 'hola' or info 'hola'
	#cisfun$

## Authors 
 Abeeb Raheem and Ogunbanjo Nimota Busayo

