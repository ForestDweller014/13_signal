#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
	if (signo == SIGINT) {
		printf("Exiting due to SIGINT signal");
		exit(0);
	}

	if (signo == SIGUSR1) {
		printf("Parent process ID: %d\n", getppid());
	}
}

int main() {
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	kill(getpid(), SIGUSR1);
	while (1) {
		printf("Process ID: %d\n", getpid());
		sleep(1);
	}
}