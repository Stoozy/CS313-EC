
# Problem 

Imagine we have graph G with weighted paths (in a matrix, so that instead of just havinga 1 or 0 to show connections, we have a number to show the weight).  We also havegraph H which is a different weighted graph.  G and H represent cities (each with 5nodes and random weighted connections as vertices).  Mr. Government would like tobuild 2 roads to attach these cities.  Create a program that places the two roads (withsome reasonable weights) between G and H.  Each of the new roads must not comefrom or go to the same node as the other new road (i.e. it cannot be that both roads leave G or enter H from the same node).   Your program should have an algorithm tocreate one large map M that includes G, H, and the two new roads.  It is best if youralgorithm can take in any sized G, H, and any number of new number of roads.

# Solution

I've solved this problem by representing the weights of each edge in an adjacency matrix. Where each road/edge's weight is the value of the cell at (v1, v2), where v1 and v2 are the vertices.

Note: 0 represents non existent edges (I know it's supposed to be infinity but this'll do for now)


A sample city of size 5 may look like this:

```
0 7 1 2 3
7 0 2 5 8
1 2 0 2 5
2 5 2 0 0
3 8 5 0 0
```

Creating the map was fairly straightforward for me. The second city (of same size), should just be offset by N and the first should stay identical.


Sample map (No new roads)
This just represents city G on the top left and H on the bottom right.

```
0 8 8 9 8 0 0 0 0 0
8 0 0 9 4 0 0 0 0 0
8 0 0 0 2 0 0 0 0 0
9 9 0 0 9 0 0 0 0 0
8 4 2 9 0 0 0 0 0 0
0 0 0 0 0 0 7 1 2 3
0 0 0 0 0 7 0 2 5 8
0 0 0 0 0 1 2 0 2 5
0 0 0 0 0 2 5 2 0 0
0 0 0 0 0 3 8 5 0 0
```


This leaves the top right quadrant to be used for creating new roads. Note: top right because, everything gets mirrored so that no edges leave the same node twice with different weights. In other words, it's not a multigraph. This is also noticable in individual cities.

```
0 8 8 9 8 9 0 0 0 0
8 0 0 9 4 0 1 0 0 0
8 0 0 0 2 0 0 9 0 0
9 9 0 0 9 0 0 0 0 0
8 4 2 9 0 0 0 0 0 0
9 0 0 0 0 0 7 1 2 3
0 1 0 0 0 7 0 2 5 8
0 0 9 0 0 1 2 0 2 5
0 0 0 0 0 2 5 2 0 0
0 0 0 0 0 3 8 5 0 0
```

This is the result of creating 3 new roads with weights 9,1 and 9. Note: the new roads do not go from the same node or to the same node twice just as specified in the question, "it cannot be that both roads leave G or enter H from the same node".

If we index city G as A-E and city H as F-J, the new roads would connect:

```
    A -> F with length 9
    B -> G with length 1
    C -> H with length 9
```

My program also  accepts any sized cities G and H and any number of new roads.
Sample output of program:

```
Enter number of nodes:
5

City G Adjacency Matrix:
0 8 8 9 8
8 0 0 9 4
8 0 0 0 2
9 9 0 0 9
8 4 2 9 0

City H Adjacency Matrix:
0 7 1 2 3
7 0 2 5 8
1 2 0 2 5
2 5 2 0 0
3 8 5 0 0

Map M:
0 8 8 9 8 0 0 0 0 0
8 0 0 9 4 0 0 0 0 0
8 0 0 0 2 0 0 0 0 0
9 9 0 0 9 0 0 0 0 0
8 4 2 9 0 0 0 0 0 0
0 0 0 0 0 0 7 1 2 3
0 0 0 0 0 7 0 2 5 8
0 0 0 0 0 1 2 0 2 5
0 0 0 0 0 2 5 2 0 0
0 0 0 0 0 3 8 5 0 0
How many roads would you like?
3
Map M:
0 8 8 9 8 9 0 0 0 0
8 0 0 9 4 0 1 0 0 0
8 0 0 0 2 0 0 9 0 0
9 9 0 0 9 0 0 0 0 0
8 4 2 9 0 0 0 0 0 0
9 0 0 0 0 0 7 1 2 3
0 1 0 0 0 7 0 2 5 8
0 0 9 0 0 1 2 0 2 5
0 0 0 0 0 2 5 2 0 0
0 0 0 0 0 3 8 5 0 0
```
