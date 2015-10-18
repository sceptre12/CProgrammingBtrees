#Major Assignment #1: Sorting with Binary Search Tree

This assignment asks you to sort the lines of an input file (or from standard input) and print the sorted lines to an output file (or standard output). Your program, called bstsort (binary search tree sort), will take the following command line arguments:

% bstsort [-c] [-o output_file_name] [input_file_name]

If -c is present, the program needs to compare the strings case sensitive; otherwise, it's case insensitive. If the output_file_name
is given with the -o option, the program will output the sorted lines to the given output file; otherwise, the output shall be the standard output. Similarly, if the input_file_name is given, the program will read from the input file; otherwise, the input will be from the standard input. You must use getopt() to parse the command line arguments to determine the cases.
