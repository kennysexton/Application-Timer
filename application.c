// Kenneth Sexton
// Cis 3207
// Project 1

/* Function Declarations */
char randomChar();

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;


int main() {
	FILE *fp;

	// For random number generation
	int seed = time(NULL);
	srand(seed);

	// Create a blank record
	fp = fopen("record.txt", "w");

	// Populates the records with random character sequences
	for(i=0; i<10; i++){
		for(j=0; j<120; j++){
			fprintf(fp, "%c", randomChar());
		}
		fprintf(fp, "\n");
	}
	//read a character sequence

}

/*--------------Functions--------------*/
char randomChar(){
	int charLookup= rand() % 51;

	switch(charLookup){
		case 0:    // beg lower 
			return 'a';
			break;
		case 1: 
			return 'b';
			break;
		case 2: 
			return 'c';
			break;
		case 3: 
			return 'd';
			break;
		case 4: 
			return 'e';
			break;
		case 5: 
			return 'f';
			break;
		case 6: 
			return 'g';
			break;
		case 7: 
			return 'h';
			break;
		case 8: 
			return 'i';
			break;
		case 9: 
			return 'j';
			break;
		case 10: 
			return 'k';
			break;
		case 11: 
			return 'l';
			break;
		case 12: 
			return 'm';
			break;
		case 13: 
			return 'n';
			break;
		case 14: 
			return 'o';
			break;
		case 15: 
			return 'p';
			break;
		case 16: 
			return 'q';
			break;
		case 17: 
			return 'r';
			break;
		case 18:
			return 's';
			break;
		case 19: 
			return 't';
			break;
		case 20: 
			return 'u';
			break;
		case 21: 
			return 'v';
			break;
		case 22: 
			return 'w';
			break;
		case 23: 
			return 'x';
			break;
		case 24: 
			return 'y';
			break;
		case 25: 
			return 'z';
			break;  // end lower
		case 26:    // beg upper
			return 'A';
			break;
		case 27: 
			return 'B';
			break;
		case 28: 
			return 'C';
			break;
		case 29: 
			return 'D';
			break;
		case 30: 
			return 'E';
			break;
		case 31: 
			return 'F';
			break;
		case 32: 
			return 'G';
			break;
		case 33: 
			return 'H';
			break;
		case 34:
			return 'I';
			break;
		case 35: 
			return 'J';
			break;
		case 36: 
			return 'K';
			break;
		case 37: 
			return 'L';
			break;
		case 38: 
			return 'M';
			break;
		case 39: 
			return 'N';
			break;
		case 40: 
			return 'O';
			break;
		case 41: 
			return 'P';
			break;
		case 42: 
			return 'Q';
			break;
		case 43: 
			return 'R';
			break;
		case 44: 
			return 'S';
			break;
		case 45: 
			return 'T';
			break;
		case 46: 
			return 'U';
			break;
		case 47: 
			return 'V';
			break;
		case 48: 
			return 'W';
			break;
		case 49: 
			return 'X';
			break;
		case 50: 
			return 'Y';
			break;
		case 51: 
			return 'Z';
			break;  // end upper

		default:
			return '0';
	}
}
