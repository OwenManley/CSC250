//Owen Manley,CSC250, Assignment #4. This assignment uses a two-dimensional array
//to mimic command line arguments. I used ChatGPT to compare and help me figure out what my errors were.

#include <stdio.h>
#include <string.h>

#define MAX_ARGS 20 //Defining the maximum amount of arguments.
#define LENGTH 20 //Defining the max number of characters per argument.

/////////////////////////////////////////////////////////////////////////////////

//Takes the input to populate the args array.

void parseCommandLine(const char *input,char args[MAX_ARGS][LENGTH], int *argc){

        char inputCopy[100]; 
//For some reason, an error would occur 
//regarding the array for the input, so I had
//to make a copy of it.
        strcpy(inputCopy, input);//Copying the input array.

        const char *delimeter = " "; 
//Tokenizes what is inputed until a space is
//entered, I believe.
        char *token = strtok(inputCopy,delimeter);

        while(token != NULL && *argc < MAX_ARGS){
//While the tokenization doesn't equal NULL, and is less than the max args, 
//copy the string & tokenize it.
                strcpy(args[*argc],token);
                (*argc)++;
                token = strtok(NULL,delimeter);
        }//end while

}// end parseCommandLine function

/////////////////////////////////////////////////////////////////////////////////

int main(){

        char input[100]; //Array for the max amount of input.
        char args[MAX_ARGS][LENGTH]; //The two dimensional array.
        int argc = 0;

        printf("Enter command-line arguments: ");
        fgets(input, sizeof(input), stdin);
//fgets essentially reads what is entered by the user, in the file associating 
//with it.

        input[strcspn(input, "\n")] = '\0';
//I believe strcspn returns the length entered by the user.

        parseCommandLine(input, args, &argc);
//Defines the command-line inputs.

/////////////////////////////////////////////////////////////////////////////////

        int i = 0;

        while(i<MAX_ARGS && args[i][0] != '\0'){
//While MAX_ARGS doesn't equal to NULL, print the number of arguments, as well as
//the inputs for each command-line argument.

 		printf("Argument %d: %s\n",i,args[i]);
                i++;
        }//end while

        printf("Number of arguments: %d\n", argc);

        if(argc == MAX_ARGS){

                printf("Error: Max number of arguments exceeded.\n");
                return 1;
        }// end if

        return 0;

}// end int main


