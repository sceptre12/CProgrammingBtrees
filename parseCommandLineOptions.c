#include "header.h"

void parseCommandLineOptions(int argc, char *argv[],int *caseSensitive,char **outputFile,char **inputFile){

        int c;
        /*
           opterr: If the value of this variable is nonzero then getopts prints an error message
                  to the standard error stream if it encounters an unkown option character or an
                  option with a missing required argument (this is the default behavior)
                  Setting it to 0 will not make getopts print any messages, but it returns
                  the character ? to indicate an error

         */
        opterr = 0;
        while((c = getopt(argc,argv, "co:")) != -1) {
                switch(c) {
                case 'c':
                        *caseSensitive = 1;
                        break;
                case 'o':
                        /*
                           optarg: This variable is set by getopt to point at the value of the
                           option argument, for those that accept arguments
                         */
                        *outputFile = optarg;
                        break;
                case '?':
                        /*
                           optopt: When getopt encounters an unkown option character  or an option
                                  with a missing  required argument  it stores that option character
                                  in this variable
                         */
                        if(optopt == 'c')
                                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                        else if(isprint(optopt))
                                /*
                                   isprint: Checks whether a passed character is printable
                                 */
                                fprintf(stderr, "Unkown Option '-%c'\n", optopt);
                        else
                                // %x prints out hex
                                fprintf(stderr, "Unkown Option character '\\x%x'\n", optopt);

                        exit(1);
                default:
                        abort();
                }
        }

        /*
           optind: Is set by the getopts to the index of next element of the argv array
                  to be processed. Once getopts has found all the option arguments
                  this can be used to determien where all the non-opion arguments begin.
         */
        *inputFile = argv[optind];
        // for(index = optind; index < argc; index++) {
        //         printf("Non-option argument %s\n\n", argv[index]);
        // }
}
