#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

pid_t cpid;

void signalHandler(int signum) {
  std::cout << "Signal " << signum << " '" << strsignal(signum) << "' sent to child PID " << cpid;
	kill(cpid, signum);
	exit(0);
}

auto main(int argc, char *argv[]) -> int {

  cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  
  if (cpid == 0) {
    execvp(argv[1], argv + 1);
    perror("execve");
    exit(EXIT_FAILURE);
  }

  signal(SIGINT, SIG_IGN);
  signal(SIGTERM, signalHandler);
  signal(SIGQUIT, signalHandler);
  signal(SIGHUP, signalHandler);
   
  int status = 0;
  waitpid(cpid, &status, 0);
  
  if (WIFEXITED(status)) {
    std::cout << "\n Child PID " << cpid << ", exited with status " << WEXITSTATUS(status);
  }

  if (WIFSIGNALED(status)) {
    std::cout << "\n Child PID " << cpid << ", killed by signal " << WTERMSIG(status) << " '" << strsignal(WTERMSIG(status)) << "'";
  }

  return 0;
}