//Owen Manley, CSC250, Assignment #9. This assignment uses input and output functions to create a copy of a file and add the pre-existing
//contents of that file into the new one.
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
        //Checking if the correct number of command line arguments are provided.
        if(argc != 2) {
                fprintf(stderr, "Error\n", argv[0]);
                exit(1);
        }// end if
        //Opening the input file to be read...
        //If it's NULL, there was an error in opening it.
        FILE *inputFile = fopen(argv[1], "r");
        if(inputFile == NULL) {
                perror("Error opening input file.");
                exit(1);
        }//end if
        //Opening output file to be written in...
        //If that is NULL after the process is gone through, print an error message.
        FILE *outputFile = fopen ("output.txt", "w");
        if(outputFile == NULL) {
                perror("Error creating output file.");
                exit(1);
        }//end if

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Count the lines and copy the content from input file to output file...

        int lineCount = 0;
//Counter for the amount of lines in input file.
        char buffer[1024];
//Adjusting the buffer size so the content can be copied.

        while(fgets(buffer, sizeof(buffer), inputFile) != NULL) {
//While loop for reading the lines of text in the input file, as long as it's not NULL, lines will continue to be read.
  fputs(buffer, outputFile);
//Puts whats in the buffer of the input file into the output file.
        lineCount++;
//Iterate the line counter since it successfully read a line for the loop.

        }// end while

//Closing both files...
//If either the input or output files != 0 when closed, there was an error. Meaning, if there was still contents left after being closed.
        if(fclose(inputFile) != 0) {
                perror("Error closing input file.");
                exit(1);
        } //end if
//Close function for output...
        if(fclose(outputFile) != 0) {
                perror("Error closing the output file.");
                exit(1);
        }//end if

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Now, to display the results...

        printf("output.txt file has been created.\n");
        printf("%d lines have been copied to output.txt\n", lineCount);

        return 0;
        //Meaning the program ran successfully.

} //end main
