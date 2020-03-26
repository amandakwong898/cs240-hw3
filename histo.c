/*
 *
 * project: hw3
 * name: Amanda Kwong
 * account: akwong
 * date: 3/5/20
 * file: histo.c
 * notes:
 *
    
 *   
 */

#include <stdio.h>




/* Complete the program */
int main(void)
{      
	/* check before and after to see if the char is either a space or non-alphanumeric
	   record all the words in a char array, and keep track of the length
	   make an integer array (0-27), initializing each element to 0, to store how many words with the same length occur
	   print stars (for loop iterating each 4000 occurrence with an asterisk)
	   print out the longest word (the word with == 27) on the first line
	   access each character using getchar()  */

	int c;
	int count = 0;
	int array[28];
	char longest[27];
	int max = 0;
	char current[27];

	for (int i = 0; i < 28; i++) {
		array[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			current[count] = c;
			count += 1;
		}
		else {
			current[count + 1] = '\0';
			if (max < count) {
				for (int i = 0; i < 27; i++) {
					longest[i] = current[i];
				}
				max = count;
			}	
			array[count] += 1;
			count = 0;
		}
	}

	printf("\n%s\n\n", longest);

	for (int i = 1; i < 28; i++) {
		printf("%2d %6d ", i, array[i]);
			for (int j = array[i]; j > 0; j -= 4000) {
				printf("*");
			}
			printf("\n");
	}

	return 0;   
}
