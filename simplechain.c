#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
   //***VARIABLE DECLARATION***
   pid_t childpid = 0;
   int i, n, j;
   int opt;
   int numProcs=4;
   int numChars=80;
   int sleeptime=3;
   int niters=1;
   int processId=0;
   
   
   
   //***GETOPT***
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
   processId = numProcs-1;
   
   for (i = 1; i < n; i++){
      if (childpid = fork()){   //FORK
         
          int result=0;
   
         if(waitpid(childpid,&result,0)==-1){     //WAIT
            printf("%s: ",argv[0]);
             perror("error: ");
            return 1;
         }
         break; //Parent process
      }
      else if(childpid == -1){
         printf("%s: ",argv[0]);
         perror("error: ");
         return 1;
      }
      else{
          //child process
         processId=processId-1;
      }
   }
 
   
   for(j = 1; j <= niters; j++){     //ITERATIONS FROM I
      char myChar;
      int offset=(numChars)*processId*niters;
      
      if(j==1){   
      fseek(stdin, offset, SEEK_SET);
      }
      
      char mybuf[numChars+1];
      for(i = 1; i<=numChars; i++){
         myChar =getc(stdin);
         mybuf[i-1]=myChar;
      }

      mybuf[numChars]='\0';
      sleep(sleeptime);

      //***PRINT RESULTS***
      fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld mybuf:%s\n",
         j, (long)getpid(), (long)getppid(), (long)childpid, mybuf);
   }
   return 0;
}
