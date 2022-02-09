#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
   pid_t childpid = 0;
   int i, n;
   int opt;
   int numProcs=4;
   int numChars=80;
   int sleeptime=3;
   int niters=0;
   char str[]="chain: Error: ";
   
   while((opt = getopt(argc, argv, "hp:c:s:i:")) != -1)
   {
      switch(opt)
      {
            case'h':
            printf("Usage:\nchain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\nnprocs Number of processes [default 4]\nnchars Number of characters read into the buffer [default 80]\nsleeptime Time to sleep in each iteration [default 3s]\nniters Numbner of iterations in the loop\ntextfile File containing text to be read through stdin\n");
            return 0;
            break;
            
            case'p':
            numProcs = atoi(optarg);
            break;
            
            case'c':
            numChars = atoi(optarg);
            break;
            
            case's':
            sleeptime = atoi(optarg);
            break;
            
            case'i':
            niters = atoi(optarg);
            break;
      }
   }
   
   n = numProcs;
   for (i = 1; i < n; i++){
      if (childpid = fork()){
         break;
      }
      
      
      else if(childpid == -1){
         perror("chain: Error:");
         return 1;
      }
   }
   
   for(i = 1; i < niters; ++i){
      sleep(sleeptime);
   }

   char myChar;
   for(i = 1; i<numChars; i++){
      myChar =getc(stdin);
      printf("Next char is: %c \n",myChar);
   }
   
   
   
   
   
   
   fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
      i, (long)getpid(), (long)getppid(), (long)childpid);

   return 0;
}
