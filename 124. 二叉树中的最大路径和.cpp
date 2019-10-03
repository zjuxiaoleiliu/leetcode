题目描述:

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.


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
    int maxPathSum(TreeNode *root) {

    	int maxSum = INT_MIN;
    	maxPathSumCore(root, maxSum);
    	return maxSum;       
    }
    //要注意这个函数返回的是经过树的根的单侧路径的最大值，由于这个递归函数的
    //操作需要遍历每一个结点，所以相当于暴力的枚举，顺便更新了最大值，总之是
    //这个函数干了两件事情，函数的返回值是这个函数的功能部分，在函数的调用过程中
    //更新update maxSum是额外间接干的事情，
    int maxPathSumCore(TreeNode*root,int & maxSum)
    {
    	if(root==nullptr)
    		return 0;
    	int left = maxPathSumCore(root->left,maxSum);
    	int right = maxPathSumCore(root->right,maxSum);
    	int curSum = root->val;
    	if(left > 0)
    		curSum+=left;
    	if(right > 0)
    		curSum+=right;
    	if(curSum > maxSum)
    		maxSum = curSum;
    	return max(max(left+root->val,right+root->val),root->val);
    }
};