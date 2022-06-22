#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main(){
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */

	//Declaring variables I will be using later
	char c[1000000];
	int count = 0;
	int checker = 1;
	int n;

	//Getting all of the command line into a character array
	while(checker){
		n = getchar();
		c[count] = n;
		count++;
		if(n == -1){
			checker = 0;
		}
	}

	//Resetting the count to make sure we can go through the array correctly
	count = 0;
	int count3 = 1;

	while(c[count] != '\0'){

		//Deals with getting the correct amonut of words
		if(c[count] == ' ' || c[count] == '\n'){
			while(c[count + count3] == ' '){
				count3++;
				tot_words--;
			}
			tot_words++;
			
		}

		//Deals with getting the correct amount of new lines
		if(c[count] == '\n'){
			tot_lines++;
		}

		//Special case dealing with two spaces in a row
		if(c[count] == ' ' && c[count + 1] == ' '){
			tot_words--;
		}

		//Deals with getting the correct amount of characters
		tot_chars++;
		count++;
	}


	//Prints the output
	printf("%d, %d, %d", tot_lines, tot_words, tot_chars - 1);
	printf("\n");

	return 0;
}

