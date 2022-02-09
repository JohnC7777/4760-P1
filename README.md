***INFO***
CS 4760
Project 1
2/8/2022
John Citrowske
Version Control: https://github.com/JohnC7777/4760-P1


***HOW TO RUN**
1. make:  type "make" and press enter
2. run: type "./chain" followed by parameters

example:
./chain -p 2 -c 5 -s 2 -i 4 < example.txt

type "./chain -h"  for help



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

6"Modify the code by adding the wait function call before the final fprintf statement. How does this affect the output of the program?
Are you able to execute with a value of n as 100?"
--waits until the child processes exits. After child process terminates, parent continues its execution after wait system call instruction. results are in different order than before. results appear top down and are in perfect order. n=100 executes with 28 processes

7:"Modify your code by replacing the final fprintf statement with four fprintf statements, one each for the four
integers displayed. Only the last one should output a newline. What happens when you run this program? Can you tell
which process generated each part of the output? Run the program several times and see if there is a difference in the
output."
--Program runs but there are many inconsistencies between tests. 
For example:

Test 1:
i:1i:3055 process ID:139676878031307parent ID:22877child ID:3056
i:1i:3056 process ID:3parent ID:1child ID:3057
i:1i:3057 process ID:3parent ID:1child ID:3058
i:1i:3058 process ID:3parent ID:1child ID:3059

Test 2:
i:1i:3080 process ID:140311343880651parent ID:22877child ID:3081
i:1i:3081 process ID:3parent ID:1child ID:3082
i:1i:3082 process ID:3parent ID:1child ID:3083
i:1i:1i:3083 process ID:3i:3084 process ID:3parent ID:1child ID:3084

--There are duplicate 'i:1', there are two process ID statements in the last line of Test 2.



8:"Modify your code by replacing the final fprintf statement with a loop that reads nchars characters from stdin one
character at a time, and puts them in an array called mybuf. The values of n and nchars should be passed as command
line options. After the loop, put a ’\0’ character in index nchars of the array so that it contains a string. Output the
PID of the process followed by a colon, a space, the string in mybuf, and a newline to stderr in a single fprintf.
Run the program for several values of n and nchars. Observe the results. Redirect the stdin from a file with some
text that should be enough to make sure that all the processes terminate normally (more than n ×nchars characters)."
-- Program outputs process ID, parent ID, child ID, and mybuf. I noticed that when I have p, s, and i set to higher numbers it will take a while to compute. time to compute is p*s*i. I noticed the program reached the end of file for example.txt so it output gibberish.

i:1 process ID:6191 parent ID:6190 child ID:0 mybuf:Lorem







