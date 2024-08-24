## Question 1 
Given a Binary Search Tree (BST) that may be unbalanced, your task is to balance it. A balanced BST is defined as a tree where the depth of the two subtrees of every node never differs by more than 1.

Example 1:

```
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4] or Output: [3,1,4,null,2] is also correct
```
Constraints:

- The number of nodes in the tree is in the range [1, 104].
- 1 <= Node.val <= 105

## Question 2
Determine the node(index) where a given binary is not balanced.

## Question 3
Given a balanced Binary Search Tree (BST) containing unique strings, determine two distinct strings from the BST that, when concatenated, result in a specified target concatenated string.

Example
```
Input: root = ["Dog","Bat","Fan","Apple",null,"Eagle","Goat"], target=AppleGoat(Apple + Goat)
Output: true
```

Approach

```
    Function treeToList(Node node, List<String> list):
        If node is NULL:
            Return list
        treeToList(node.left, list)
        list.append(node.data)
        treeToList(node.right, list)
        Return list

    Function isPairPresent(Node node, String target):
        List<String> a1 = empty list
        List<String> a2 = treeToList(node, a1)
        start = 0
        end = size of a2 - 1
        
        While start < end:
            If a2[start] + a2[end] == target:
                Print "Pair Found: " + a2[start] + " + " + a2[end] + " = " + target
                Return True
            If a2[start] + a2[end] > target:
                end--
            If a2[start] + a2[end] < target:
                start++
        Print "No such values are found!"
        Return False
```



Time Complexity
- O(N), for inorder traversal, O(N), for pair checking. Total O(N)

## Question 4
kth smallest string from AVL tree in O(logn).

## Question 5
Given a sorted array of strings, construct a balanced Binary Search Tree (BST). The binary search tree property should be maintained, where for any given node, the left subtree contains only nodes with strings that are lexicographically less than the node's string, and the right subtree contains only nodes with strings that are lexicographically greater

Approach

```
Function sortedArrayToBST(arr, start, end):
    If start > end:
        Return NULL
    mid = (start + end) / 2
    root = newNode(arr[mid])
    root.left = sortedArrayToBST(arr, start, mid - 1)
    root.right = sortedArrayToBST(arr, mid + 1, end)
    Return root
```
Time Complexity

- O(N), function processes each element of the array once.


## Question 6
Sort a given Linked List and convert to Balanced BST.

## Question 7
Given a Balanced BST T, and two strings s1 and s2 such that s1< s2, write a function that prints all the 
strings in the tree in the range [s1, s2].
