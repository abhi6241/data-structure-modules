# Coding all Data Structures Modules

This repository holds C implementations for many common data-structure and algorithm exercises used for learning and practice. Below is a grouped list of the question/source files included in this repository.

## Contents (questions)

### arrays/
- `ackermans.c` — Ackermann's function
- `arrayinsertdelete.c` — Insert and delete operations on an array
- `binarysearchrecursion.c` — Binary search (recursive)
- `displaysmallestlargest.c` — Display smallest and largest elements in an array
- `permutations.c` — Generate permutations of an array/string
- `removeduplicates.c` — Remove duplicates from an array
- `towersofhanoi.c` — Towers of Hanoi

### infixprefixpostfix/
- `infixtopostfix.c` — Convert infix expression to postfix
- `postfix.c` — Evaluate/handle postfix expressions

### linkedlist/
- `circularlinkedlist.c` — Circular linked list operations
- `dll.c` — Doubly linked list (DLL) operations
- `polynomialusingsll.c` — Polynomial representation using singly linked list
- `queueusingsll.c` — Queue implemented using singly linked list
- `sll.c` — Singly linked list (SLL) basic operations
- `slladdition.c` — Add two numbers represented by SLLs
- `stackusingsll.c` — Stack implemented using singly linked list

### stackqueuewitharray/
- `circularqueue.c` — Circular queue implementation (array)
- `queue.c` — Queue implementation (array)
- `stack.c` — Stack implementation (array)

### strings/
- `naivepatternmatching.c` — Naive string pattern matching
- `stringhandlingfunctions.c` — Common string handling helper functions

### structures/
- `magicsquare.c` — Create a magic square
- `magicsquareornot.c` — Check whether a matrix is a magic square
- `polynomial.c` — Polynomial operations (array/structure-based)
- `sparsematrix.c` — Sparse matrix representation
- `sparsematrixaddition.c` — Add two sparse matrices
- `symmetricornot.c` — Check if a matrix is symmetric

## How to compile
Compile any C source file with gcc. Example (from repository root):

```bash
gcc -o bin/<output-name> path/to/source-file.c
./bin/<output-name>
```

Replace `<output-name>` and `path/to/source-file.c` with the desired values. You can also create simple Makefile rules if you want to build multiple programs more conveniently.
