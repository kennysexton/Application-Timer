// Kenneth Sexton
// Cis 3207
// Project 1

/* Function Declarations */
char randomChar();
int randomLine();

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i, j, k, count, runNum;



// for(i=0; i < 10; i++)
// 	// 	megamatrix[i] = (char *)malloc(121 * sizeof(char));

int main() {
	FILE *fp;

	// For random number generation
	int seed = time(NULL);
	srand(seed);

	char line[121];  // + 1 for '\n' character at i[120]
	char megamatrix[10][121]; // 1:1 map of the record file
	char selectArray[121];   // + 1 for '\n' character at i[120]

	for(k=0; k<10000; k++){

			// Create a blank record
		fp = fopen("record.txt", "w+");

			// Populates the records with random character sequences
		for(i=0; i<10; i++){
			for(j=0; j<120; j++){
				megamatrix[i][j] = randomChar();   // Store the same file map to our MegaMatrix
				fprintf(fp, "%c", megamatrix[i][j]);
			}
			megamatrix[i][120] = '\n';
			fprintf(fp, "\n");
		}
		rewind(fp); //reset file pointer
		i = 1; // reset i

		count = randomLine();
		//printf("Count: %d\n", count);

			//read a random character sequence
		while((fgets(line, 122, fp) != NULL) && i < count + 1 ){
			 i++;
		}
					//extract random line from Mega Matrix
		for(j=0; j< 121; j++){
			i = count;
			selectArray[j] = megamatrix[count][j]; 
		}
			// Compare
		if(strcmp(selectArray,line) != 0){  // If for some reason the read does not match the document, the program will close
			printf("%s\n", "Error-- arrays are NOT equal");
			printf("Failed on run %d\n", k);
			exit(0);
		}
		fclose(fp);
	} // End reapeat forloop
	printf("made it! Program ran %d times", k);
}

/*--------------Functions--------------*/
char randomChar(){
	return rand() % 58 + 65; // ASCII characters 65-122
}

int randomLine(){  // Random number 0-9
	return rand() % 10;
}