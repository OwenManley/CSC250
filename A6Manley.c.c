//Owen Manley, CSC250, Assignment 6. This program reads multiple lines of text and generates a table of occurence of words by their lengths
//using pointer notation instead of array notation.
#include <stdio.h>//For printf statements.
#include <string.h>//Used for the strlen API.
#define SIZE 100//Used to determine the max size of the input string as a whole to a fixed value.

int main(){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int wrdOccurence[10] = {0};//There will be 10 word occurences, from 1 to 10 letters in a word.
        int *wrdPtr = wrdOccurence;//wrdPtr is a pointer to wrdOccurence.
        char str1[SIZE];//Array for input string.
        char *strPtr = str1;//This is a pointer to the input string.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        printf("Enter your string:\n");
        fgets(str1,sizeof(str1),stdin);//Using fgets to retrieve the input, similar to Scanner in Java.
        puts("\n");//A new line for better formatting when the program runs.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int i;//Declaring i for the for loop.
        int wrdCounter = 0;//Initializing a counter to add up the number of words at the associated word occurence.
        for(i = 0; i <strlen(str1); i++){//Iterating throughout the input string.
                if(*(strPtr+i) == ' ')//These if statements are dereferencing the pointers to retrieve the associated values they're pointing to.
                {
                        (*(wrdPtr+wrdCounter-1))++;//Point to the word occurence and iterate the counter for that associated word length.
                        wrdCounter = 0;

                        if(*(strPtr+i) == '\0')
                        {
                                (*(wrdPtr+wrdCounter-1))++;
                                wrdCounter = 0;
				if(*(strPtr+i) == '\n')
                                {
                                        (*(wrdPtr+wrdCounter-1))++;
                                        wrdCounter = 0;
                                }//end inner if
                        }//end inner if

                }// end if. If the input string equals any of these, the word counter is going to remain zero since no word was inputed.

                else
                {
                        wrdCounter++;//Iterate the word counter if there is a word.
                }//end else. 
	}//end for
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        printf("   Word Length:\t   Occurence:");//Print the Word length and occurence in a list format.
        for(i=0;i<10;i++){//Loop through the occurences.
                printf("\n\t%d\t\t%d\n",i+1,*(wrdPtr+i));//i is the Occurence. Then it dereferences the pointer to print the number of words at the following 
		//occurence.
        }//end for

}//end main