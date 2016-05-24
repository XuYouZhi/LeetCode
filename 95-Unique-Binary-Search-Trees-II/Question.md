# 95. Unique Binary Search Trees II

[Original Page](https://leetcode.com/problems/unique-binary-search-trees-ii/)

Given _n_, generate all structurally unique **BST's** (binary search trees) that store values 1..._n_.

For example,  
Given _n_ = 3, your program should return all 5 unique BST's shown below.

<pre>   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
</pre>

confused what `"{1,#,2,3}"` means? [> read more on how binary tree is serialized on OJ.](#)

<div class="spoilers" style="display: none;">  
**OJ's Binary Tree Serialization:**

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:  

<pre>   1
  / \
 2   3
    /
   4
    \
     5
</pre>

The above binary tree is serialized as `"{1,2,3,#,#,4,#,#,5}"`.</div>

<div>

[Subscribe](/subscribe/) to see which companies asked this question

</div>

<div>

<div id="tags" class="btn btn-xs btn-warning">Show Tags</div>

<span class="hidebutton">[Tree](/tag/tree/) [Dynamic Programming](/tag/dynamic-programming/)</span></div>

<div>

<div id="similar" class="btn btn-xs btn-warning">Show Similar Problems</div>

<span class="hidebutton">[(M) Unique Binary Search Trees](/problems/unique-binary-search-trees/) [(M) Different Ways to Add Parentheses](/problems/different-ways-to-add-parentheses/)</span></div>