# Problem 

Create an algorithm that finds the longest path from a chosen node N_1 to anotherchosen node N_2 from a graph G.

# Solution

In an adjacency matrix the (row,col) cell represents the weight between two nodes row and col respectively. This information can be used to get the longest path from one path to the next.

I basically go over every possible path from N_1 to N_2 to get the maximum.

Here's what the code looks like:

```cpp

int longest_path(int v1, int v2, int cpl, int N, int ** graph){
    static int max;

    int cl = get_cl(v1, v2, cpl, graph);
    if(cl>max) max = cl;

    for(int c=v1+1; c<N; ++c){
        longest_path(c, v2, cpl+graph[v1][c], N, graph);
    }

    return max;
}

```

v1 is N_1 and v2 is N_2 in the question (v for vertex). First lets cover how to get the max.

I've created a method that checks for the weight of the connection to N_2 from any given node. If it's not 0 (meaning there is a connection), we return the value plus the given current path length (cpl). Otherwise just return cpl, and continue with the loop.

Code:
```cpp
int get_cl(int v1, int v2, int cpl, int ** graph){
    if(graph[v1][v2] != 0)
        return cpl+graph[v1][v2];
    return cpl;
}
```

After iterating every possible path, we can have the maximum.

Let's apply the above algorithm to the following graph:

```
0 8 8 1 
8 0 9 1 
8 9 0 1 
1 1 1 0 
```

Let 0..4 be A..D

Then the graph has the following connections and weights:

```
 A->{B:8, C:8, D:1}
 B->{A:8, C:9, D:1}
 C->{A:8, B:9, D:1}
 D->{A:1, B:1, C:1}
```

If we want to find the greatest distance from A to D we start by calling `longest_path(A(0),D(3), 0, 4, graph)`.

Then the method calls `get_cl(A(0), D(3), 0, graph)` and `graph[0][3]` is 1 which is greater than 0 so we return `0+1` and since `cl>max` (1>0) we set `max = cl`

Max is now set to 1;

Now we continue with the loop.

starting at A+1 or (0+1), we check every row value (connection) for a path leading to D or `0`;

so the call would look like `longest_path(B(1), D(3), 8, 4, graph)` which then checks Bs connection to D by calling `get_cl(B(1), D(3), 8, graph)` which returns 1 also and we don't update max because it's not greater than 1. cpl is 8 because the distance from Node A to B is 8.

Since we are still in the call `longest_path(B(1), D(3), 8, 4, graph)` we have to continue with the loop in order to find the greatest distance from B to D (as a result possibly finding greatest distance from A->D).

Now we check Cs connection to D. cpl for the next call gets updated to 8+9 where 8 is the original cpl and 9 is the distance from C to D. Now, `longest_path(C(2), D(3), 17, graph)` get's called. Then it gets the total distnce to D now, 17+1 where 17 is the original cpl and 1 is Cs distance to D. which is 18 and since 18>17, max gets updated.


This gets repeated until the maximum distance is found through intermediate nodes or a direct connection to the destination node.










