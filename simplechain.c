#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
   pid_t childpid = 0;
   int i, n;
   int opt;
   
   while((opt = getopt(argc, argv, "hp:c:s:i:")) != -1)
   {
      switch(opt)
      {
            case'h':
            printf("Usage:\nchain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\nnprocs Number of processes [default 4]\nnchars Number of characters read into the buffer [default 80]\nsleeptime Time to sleep in each iteration [default 3s]\nniters Numbner of iterations in the loop\ntextfile File containing text to be read through stdin\n");
            return 0;
            break;
            
            case'p':
            printf("Help Message");
            break;
            
            case'c':
            printf("Help Message");
            break;
            
            case's':
            printf("Help Message");
            break;
            
            case'i':
            printf("Help Message");
            break;
      }
   }
   
   if (argc != 2) {
      fprintf(stderr, "Usage: %s processes\n",argv[0]);
      return 1;
   }
   n = atoi(argv[1]);
   for (i = 1; i < n; i++)
      if (childpid = fork())
         break;

   fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
      i, (long)getpid(), (long)getppid(), (long)childpid);

   return 0;
}
