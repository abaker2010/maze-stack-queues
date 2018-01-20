# a-mazing-stacks-n-queues
Creating amazing things using stacks and queues


## TL;DR;

The goal of this homework is to implement a Stack to generate and solve a maze using a depth-first-search routine, as well as implement a Queue to solve a maze using breadth-first search.


## Part One

### Three Classes

You must create three classes - one primary data structure, and two secondary data structures:

1. Primary: Create a Linked-List Data Structure
2. Secondary: Create an O(1) Linked-List based Stack
3. Secondary: Create an O(1) Linked-List based Queue

Your linked list should be able to store some arbirtrary structure (for now a struct containing 3 integers):

```
struct cell{ 
         int x-coor;
         int y-coor;
         int visit-status;
}
```

You might need to change the contents of cell later on...

### Testing

You must also create test code that is capabable of exercising the three data structures.

### Structure

Include the following in you repository using the following structure:

- [ ] README.md
- [ ] Makefile
- [ ] /src
- [ ]  -mazeCell.h
- [ ]  -stack.[h|cpp]
- [ ]  -queue.[h|cpp]
- [ ]  -list.[h|cpp]
- [ ]  -/test
- [ ]   --test_stack.cpp
- [ ]   --test_queue.cpp
- [ ]   --test_list.cpp



## Part Two

Coming soon! All about the mazes!

