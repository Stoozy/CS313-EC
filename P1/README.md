# Problem 

Create a ternary tree (instead of binary - having two children, every node should havethrough children).  Compare the search time between binary and ternary trees for verylarge trees.

# Solution

Binary trees have a root node and a left and right node. The left and right nodes are roots to a subtree of the original tree. My program inserts a smaller value to the left and a larger value to the right, equal values are omitted.

This seemed very similar to a double linked list where there was a next and prev pointer for each node but here it's used differently.

Ternary trees were very similar to binary trees, except it allows the repetition of values. By having three nodes, left, right, and down. Where down has a value equal to that of the root value. The rest is the same as binary tree. 



Results (100 million nodes, 10 million searches)

```
Binary Tree search time total: 190ms
Ternary Tree search time total: 159ms
```

