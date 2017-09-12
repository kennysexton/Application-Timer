#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	FILE *fp;
	
	struct timeval begin, end;

	// Create a blank record
	fp = fopen("timer1.txt", "w+");

	gettimeofday(&begin, NULL);
	fprintf(fp, "Start time (seconds): %ld\n", begin.tv_sec);
	fclose(fp);

	pid_t pid=fork();
	if(pid==0){ //In child process
		execlp("./application", "application", NULL);
		printf("This will not be printed if the execlp call succeeds\n");
	}
	else{ // In parent process
		printf("you are in the parent process\n");
		waitpid(pid,NULL, 0);
	}

	
	//printf("Current time (microseconds): %ld\n", begin.tv_usec);

	
}
