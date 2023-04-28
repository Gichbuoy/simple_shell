Creating my own shell project
A shell is software that provides an interface for an operating system’s users to provide access to the kernel’s services. 
A shell should be able to:
	-print prompt
	-Read a line
	-parse (build a tree representaion)
	-Execute

Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
