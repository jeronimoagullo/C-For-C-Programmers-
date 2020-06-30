# C-For-C-Programmers-
This repository contains the source code that I wrote for the "C++ for C programmers" course which can be found in [coursera](https://www.coursera.org/learn/c-plus-plus-a/home/welcome).

## Homework 1 - C code rewritting
The first part of the lesson has the aim to show the differences beetwen C and C++. For this reason, the final homework is the rewriting of a simple C code.

## Homework 2 - Dijstra algorithm
The second part addresses the object oriented programming paradigm. The application of the theory consists in writting in C++ the well-known dijsktra algorithm is implemented. For this target, I have implemented three different classes:

* **Graph class**, which uses the list representation for the graph and has also a constructor for generating a random graph with a given density.
* **PriorityQueue class**, which implements a min-heap in order to have fast access to the minimum path with only one operation. A good explication of the implemented heap can be found from the [UPV university](https://www.youtube.com/watch?v=AD_J4ZUheik).
* **ShortestPath**, which is the main class and has one method to calculate the minimum distance and another to calculate the route of the minimum path.

All the classes are used in the main file, which implements different tests. This file demostrates the proper functionality of the classes. The shortest path algorithm is tested with the path found in this [video](https://www.youtube.com/watch?v=LLx0QVMZVkk).

## Homework 3 - Minimum Spanning Tree
The third homework extends the previous homework classes. The Graph class was improved adding a new constructor for reading a graph from a txt file. Moreover, a new class is added to the project:

* **PrimMST**, which implements the Prim's method to calculate the minimum spanning tree. This class has a constructor with a graph object as parameter and one method to calculate the minimum spanning tree.

The [spanning tree](https://en.wikipedia.org/wiki/Prim%27s_algorithm) is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight. The method implemented in this homework is the [Prim's method](https://en.wikipedia.org/wiki/Prim%27s_algorithm)

