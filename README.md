# C-For-C-Programmers-
This repository contains the source code that I wrote for the "C++ for C programmers" course which can be found in [coursera](https://www.coursera.org/learn/c-plus-plus-a/home/welcome).

## Homework 1 - C code rewritting
The first part of the lesson has the aim to show the differences beetwen C and C++. For this reason, the final homework is the rewriting of a simple C code.

## Homwork 2 - dijstra algorithm
The second part addresses the object oriented programming paradigm. The application of the theory consists in writting in C++ the well-known dijsktra algorithm is implemented. For this target, I have implemented three different classes:

* **Graph class**, which uses the list representation for the graph and has also a constructor for generating a random graph with a given density.
* **PriorityQueue class**, which implements a min-heap in order to have fast access to the minimum path with only one operation. A good explication of the implemented heap can be found from the [UPV university](https://www.youtube.com/watch?v=AD_J4ZUheik).
* **ShortestPath**, which is the main class and has one method to calculate the minimum distance and another to calculate the route of the minimum path.

All the classes are used in the main file, which implements different tests. This file demostrates the proper functionality of the classes.
