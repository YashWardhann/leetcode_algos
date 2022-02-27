# [LEETCODE 310] Minimum Height Tree

### Initution: 

In this problem, we are asked to find the MHT's root labels for a given Tree. 

We notice that a leaf node can never be the root of a MHT (unless N = 2). The proof for this claim is given below: 

1) Assume that a leaf node L is a MHT root. 
2) Since, L is a leaf node, it would have a parent P at a distance 1. 
3) Now, from the leaf node L, let's say we can reach an arbitary node U with a walk size of W. 
4) Since P is the parent of L, it must exist in the walk from L -> U. So, by this, the walk size from P->U would be of walk size W-1. 
5) Therefore, since every node in the tree can be visited by the parent in a smaller walk size, L cannot be a MHT root. 

Hence, adding leaf nodes to an existing tree will not change the MHT root node. 

Now, by this two claims, we can solve this problem by recursion. Firstly, we find out all the leaf nodes of the given tree. Then, we can recursively find the MHT root node of the inner tree, by removing all of the leaf nodes. The inner most nodes left should therefore be the required MHT nodes. 

### Complexity Analysis

Time Complexity: O(|V|) 
Space Complexity: O(|V|)
