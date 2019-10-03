same-tree
题目描述:
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally 
identical and the nodes have the same value.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        //为空的次数，层层递进
    	if(p == nullptr && q == nullptr)//都为空
    		return true;
        if(p == nullptr || q == nullptr)//有一个为空
        	return false;
        if(p->val != q->val)//都不为空
        	return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};