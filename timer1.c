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

int main(){
	FILE  *st, *en; // Start and End pointers
	FILE  *wp;  // write pointer
	int i;

	char sline[17];	 // Start Line
	char eline[17];  // End Line
	unsigned long start;
	unsigned long end;

	st = fopen("start.txt", "w");    // Creates or clears the file
	fclose(st);
	en = fopen("end.txt", "w");    // Creates or clears the file
	fclose(en);
	wp = fopen("timer1.txt", "w");    // Creates or clears the file
	fclose(wp);
	
	for(i=0; i<200; i++){
		
			// write a start timestamp
		st = fopen("start.txt", "a");
		fprintf(st, "%ld\n", timestamp());
		fclose(st);

		pid_t pid=fork();
		if(pid==0){ //In child process
			execlp("./application", "./application", NULL);
			printf("This will not be printed if the execlp call succeeds\n");
		}
		else{ // In parent process
			//printf("you are in the parent process\n");
			waitpid(pid,NULL, 0);
		}
	}
		/* File reading */
	st = fopen("start.txt", "r");  // read from start times
	en = fopen("end.txt", "r");   // read from end times
	wp = fopen("timer1.txt", "w"); // writes to the timer text file
	while(fgets(sline, 17, st) != NULL && fgets(eline, 17, en) != NULL){  // read line strings until the end of file
		if (sline[0] != '\n' && eline[0] != '\n'){		// Fix issue where fgets would read in '\n' characters as seperate strngs
			start = strtoul(sline, NULL, 0);
			end = strtoul(eline, NULL, 0);
			
			fprintf(wp, "%lu\n", durration(start,end));  // Writes times to timer1.txt
			
		} else {
			continue;
		}
	}
		// Close files
	fclose(st);
	fclose(en);
	fclose(wp);

	if(remove("start.txt") != 0){	// Remove no longer relevant file
		printf("failed to remove start.txt\n");
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