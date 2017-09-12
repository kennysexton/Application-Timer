#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Functions */
unsigned long timestamp();



int main(){
	FILE *fp;
	int i;

	fp = fopen("timer1.txt", "w");    // Creates or clears the file
	fclose(fp);
	
	for(i=0; i<20; i++){
		// Create a blank record
		fp = fopen("timer1.txt", "a");
		fprintf(fp, "%ld\n", timestamp());
		fclose(fp);

		pid_t pid=fork();
		if(pid==0){ //In child process
			execlp("./application", "./application", NULL);
			printf("This will not be printed if the execlp call succeeds\n");
		}
		else{ // In parent process
			printf("you are in the parent process\n");
			waitpid(pid,NULL, 0);
		}
	}
}

unsigned long timestamp(){ //returns current time in microseconds
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (1000000 * tv.tv_sec + tv.tv_usec);
}
