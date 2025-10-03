# LINUX processes interaction
## BRIEF
This repository clearly demonstrates how processes interact with each other in Linux.
## KEY POINTS
- The first child is created using fork, the second using vfork, followed by a replacement with another program.
- All three processes have delays and output their attributes to the same file.
- The order in which attributes are output to the file
  should be determined by the process delays, which are specified as parameters
  of the program.
## LAUNCH
1. Locate root and install GNU C++ compiler
```bash
cd
sudo apt install g++
```
2. Locate parent folder
```bash
cd PARENT_ROOT
```
3. Git clone project to desired directory
```bash   
git clone https://github.com/bokachevv/LINUX_processes_interaction DESIRED_DIR
```
4. Locate desired directory and compile programs (order is necessary)
```bash
cd DESIRED_ROOT
g++ -o child2 child2.cpp write.cpp
g++ -o main main.cpp write.cpp
```
5. Launch with desired arguments
```bash
./main result.txt 1 5 3
```
6. Open .txt to see results
```bash
cat result.txt
```