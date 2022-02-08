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
            printf("Help Message");
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
