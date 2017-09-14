// Kenneth Sexton
// Cis 3207
// Project 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Functions */
unsigned long timestamp();
unsigned long durration(unsigned long start, unsigned long end);



int main(){		// Timer 2
	FILE *fpA, *fpB, *fpC, *wp;
	int i, k;

	char startA[17];
	char startB[17];
	char end[17];

	unsigned long startTimeA;
	unsigned long startTimeB;
	unsigned long endTime;

	fpA = fopen("forkA.txt", "w");    // Creates or clears the file
	fclose(fpA);
	fpB = fopen("forkB.txt", "w");    // Creates or clears the file
	fclose(fpB);
	fpC = fopen("end.txt", "w");    // Creates or clears the file
	fclose(fpC);
	wp = fopen("timer2.txt", "w");    // Creates or clears the file
	fclose(wp);
	
	for(i=0; i<100; i++){
		
			// write a start timestamp
		fpA = fopen("forkA.txt", "a");
		fprintf(fpA, "%ld\n", timestamp());
		fclose(fpA);

		pid_t forkA=fork();
		if(forkA == 0){ //In child process
			execlp("./application", "./application", NULL);
			printf("This will not be printed if the execlp call succeeds\n");
		}
		else{ // In parent process
			//printf("you are in the parent process\n");
			waitpid(forkA,NULL, 0);
		}

		fpB = fopen("forkB.txt", "a");
		fprintf(fpB, "%ld\n", timestamp());
		fclose(fpB);

		pid_t forkB = fork();

		if(forkB == 0){ //In child process
			execlp("./application", "./application", NULL);
			printf("This will not be printed if the execlp call succeeds\n");
		}
		else { // In parent process
			//printf("you are in the parent process\n");
			waitpid(forkB,NULL, 0);
		}
	}	

	int iterator = 0;
	k = 0;
		/* File reading */
	fpA = fopen("forkA.txt", "r");  // read from forkA Start times
	fpB = fopen("forkB.txt", "r");   // read from forkB Start times
	fpC = fopen("end.txt", "r");   // read from end times
	wp = fopen("timer2.txt", "w"); // writes to the timer text file

	while(((fgets(startA, 17, fpA) != NULL && fgets(startB, 17, fpB) != NULL)) && fgets(end, 17, fpC) != NULL){
		
		if (startA[0] != '\n'){  // Fix for fgets reading in newline characters instead of numbers
			startTimeA = strtoul(startA, NULL, 0);
		}

		if (startB[0] != '\n'){
			startTimeB = strtoul(startB, NULL, 0);
		}

		if (end[0] != '\n'){
			endTime = strtoul(end, NULL, 0);
		}
		
		if(iterator % 2 == 0){  // Compares fork A results
			fprintf(wp, "%lu\n", durration(startTimeA,endTime));
			printf("%s%d\n", "printed forkA on ", iterator);
		}
		else { //iterator % 2 == 1
			fprintf(wp, "%lu\n", durration(startTimeB,endTime)); // Compares fork B results
			printf("%s%d\n", "printed forkB on ", iterator);
		}
		fgets(end, 17, fpC);
		iterator++;
	}

	fclose(fpA);
	fclose(fpB);
	fclose(fpC);
	fclose(wp);

	if(remove("forkA.txt") != 0){	// Remove no longer relevant file
		printf("failed to remove forkA.txt\n");
	}

	if(remove("forkB.txt") != 0){	// Remove no longer relevant file
		printf("failed to remove forkB.txt\n");
	}

	if(remove("end.txt") != 0){		// Remove no longer relevant file
		printf("failed to remove end.txt\n");
	}
}

	/* Functions */
unsigned long timestamp(){ //returns current time in microseconds
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (1000000 * tv.tv_sec + tv.tv_usec);
}

unsigned long durration(unsigned long start, unsigned long end){  // Gets start time durration: END - START
	return end - start;
}
