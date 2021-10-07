# CS 410 - Icelandic Saga Parser

### Setup

In order to run this program, flex must first be installed. To install flex, run the following commands:

`sudo apt update`
`sudo apt install flex`

Additionally, GCC must be installed to compile the generated C file, but I think that comes pre installed on most UNIX distributions. While programming this project, I used WVU's LOUD VM (an Ubuntu VM) which can be found here: 
https://lcseesystems.wvu.edu/services/loud

### Execution

Executing the program is simple. I've created a bash script called "run.sh" which runs all the necessary commands to compile, run, and sort. If run.sh is not already an executable, you will first need to run

`chmod 777 run.sh`

Now, with run.sh as an executable, run the script:

`./run.sh`

### Results

The bash script first moves the contents main.c into main.lex. Next, it runs flex on main.lex to generate a lex.yy.c file. GCC is then executed on this new .c file to create a.out.

Input from Grettis saga is pumped through a.out and the output is directed into unsorted.csv. This csv file contains the unsorted KWIC table for the first two chapters of Grettis saga. Because it is a csv, this file can be opened with a program like MS Excel to view its contents. 

Finally, the unsorted csv file is used as input to the UNIX sort command. It is sorted with the first column as key 1, second column as key 2, and third column as key 3. The output of this command is redirected into sorted.csv which can also be opened with a program like MS Excel.