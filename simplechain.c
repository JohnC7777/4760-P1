#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
   pid_t childpid = 0;
   int i, n;
   
    while((opt = getopt(argc, argv, “:if:lrx”)) != -1) 
    { 
        switch(opt) 
        { 
            case ‘h’: 
              printf("Help Message");
              break;
            case ‘l’: 
            case ‘r’: 
                printf(“option: %c\n”, opt); 
                break; 
            case ‘f’: 
                printf(“filename: %s\n”, optarg); 
                break; 
            case ‘:’: 
                printf(“option needs a value\n”); 
                break; 
            case ‘?’: 
                printf(“unknown option: %c\n”, optopt);
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
