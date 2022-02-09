***INFO***
CS 4760
Project 1
2/8/2022
John Citrowske
Version Control: https://github.com/JohnC7777/4760-P1


***NOTES**




***OBSERVATIONS***


1: "Run your program and observe the results for different number of processes."
---ran program with small number of processes and large number. runs smoothly

2:"redraw Figure 3.2 by filling in actual PIDs of the processes in the figure for a run with command-line argument value of 4."
--ran with command-line argument value of 4.
i:1 process ID:927 parent ID:22877 child ID:928
i:2 process ID:928 parent ID:927 child ID:929
i:3 process ID:929 parent ID:1 child ID:930
i:4 process ID:930 parent ID:929 child ID:0


3: "Experiment with different values for the number of processes up to a maximum of 100 processes. Observe the fraction that are adopted by init."
---approximately 23% of processes were orphans that were adopted by INIT in this test

4:"Place sleep(10); directly before the final fprintf statement in the code. Make the previous observation again."
--approximately 55% of processes were orphans that were adopted by INIT in this test

5:"Put a loop around the final fprintf in your code. Have the loop execute k times. Put sleep(m); inside this loop just before the fprintf statement. Pass k and m using command line options.(I think there was a typo in the P1 prompt. I think it meant s and i) Run the program for several values of n, k, and m. Observe the results."
---Ran the program several times with several different values. time it takes seems to be k*m (s*i) so as long as those are fairly small the program wont take too long. also ran with several values for n

6:

7:

8:
