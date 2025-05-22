//Owen Manley, CSC250, Assignment 3. This assignment takes command line numbers (grades), and creates a histogram out of them. I had the assistance of Drew, and used ChatGPT a few times to find errors in my program since I was using PuTTY. 
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char*argv[])
{
int i,j; //Used in for loops.
int counter = 0; //Used later on for gradeArr.
int maxGrade = 0; //Used to find the maximum grade later on.
int gradeArr[argc - 1]; //Not sure why this works but allows gradeArr to be what is imputted in the command line. I think?
int median = 0;
int totalGrade = 0; //Used to find the mean.

        if(argc < 2)//Will return this error if nothing is inputted.
        {
                printf("No valid grades entered.");
                return 1;
        } //end if

        for(i = 1; i < argc; i++) //Will go through the first number instead of the execution statement.
        {
                int grade = (atoi(argv[i])); //Takes a command line argument & turns it into a variable.

        if(grade < 0 || grade > 100)// If the grade is below 0 or above 100, print an error message.
        {
                printf("%d is invalid. Grade must be between 0-100\n", grade);

        }// end if

        else //If the grade is within the range it goes here.
        {
                gradeArr[counter] = grade; //Adding the values to counter to store it.
                totalGrade += grade; //Adding each grade to get a total.
                counter++; //Iterates so another grade can be entered.

                if(grade > maxGrade) //Used to determine the maximum.
                {
                        (maxGrade = grade);
		}// end if

        }// end else

        }// end for

        for(i = 0; i < counter  - 1; i++) //Bubble sort, wanted to try another sort method but they seemed intimidating.
        {
                for(j = 0; j < counter - i - 1; j++)
                {
                        if(gradeArr[j] > gradeArr[j + 1])
                        {
                                int temp = gradeArr[j];
                                gradeArr[j] = gradeArr[j + 1];
                                gradeArr[j + 1] = temp;
                        }// end if
                }// end inner for 
        }// end for
	
	 printf("Histogram:\n"); //Print the Histogram.

        for (i = 0; i < counter - 1; i ++)//Counter is "counter - 1" since the value at max counter is not apart of what was entered.
        {
                if (i == 0 || gradeArr[i] != gradeArr[i - 1]) // If i is the first element or the element of gradeArr isn't the same as the last enter if statement
                {
                        int duplicates = 1; // Each variable starts at 1.

                        while(i < counter && gradeArr[i] == gradeArr[i + 1])// If i is a duplicate it enters here.
                        {
                                duplicates++; // Adds duplicates to the histogram.
                                i++;// Iterates so duplicates can keep being added if neccessary.
                        }

                printf("Number of %d's: %d\n", gradeArr[i], (duplicates)); // Prints the contents of the histogram.

                }
        }

	 if(argc % 2 == 0) // If argc is even or odd it will find the median.
        {
                median = ((gradeArr[argc/2-1] + gradeArr[argc/2])/2); // If its even, it will add both middle values and find the average.
        }

        else
        {
                median = (gradeArr[(argc)/2]); //If it's odd, it will find the value in the middle.
        }

        printf("Median: %d\n", median); // Prints the median.
        double mean = (double)totalGrade/counter; //Calculates the mean.
        printf("Mean: %.2f\n", mean); // Prints the mean.

}// end int main


                                
