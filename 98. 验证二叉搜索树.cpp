题目描述

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as"{1,2,3,#,#,4,#,#,5}".

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

方法1：根据BST的定义
class Solution {
public:
    bool isValidBST(TreeNode *root) {

    	if(root == nullptr)
    		return true;

    	int min = root->val;
    	int max = root->val;
        
        return isValidBSTCore(root,min,max);
    	
        
    }

    bool isValidBSTCore(TreeNode *root,int & min,int & max){

       
    	if(root->left != nullptr)
    	{
    		int minLeft = root->left->val;
    		int maxLeft = root->left->val;

    		bool left = isValidBSTCore(root->left,minLeft,maxLeft);
    		if(left == false || maxLeft >= root->val)
    			return false;
            else
            	min = minLeft;

    	}
    	if(root->right != nullptr)
    	{
    		int minRight = root->right->val;
    		int maxRight = root->right->val;

    		bool right = isValidBSTCore(root->right,minRight,maxRight);
    		if(right == false || minRight <= root->val)
    			return false;
            else
            	max = maxRight;

    	}

    	return true;
 
    	}
};

方法2：如果一颗二叉树是一颗二叉搜索树，那么对这棵树进行中序遍历，得到的是一个递增排序的访问序列
中序遍历，递归方法,思路类似于剑指offer中将二叉搜索树BST变为递增排序的双向链表的思路

class Solution {
public:
    bool isValidBST(TreeNode *root) {

    	if(root == nullptr)
    		return true;
    	TreeNode * pre = nullptr;       
        return isValidBSTCore(root,pre);        
    }

    bool isValidBSTCore(TreeNode *root,TreeNode * & pre){

    	if(root->left)
    	{
    		if(!isValidBSTCore(root->left,pre))
    			return false;
    	}

    	if(pre!=nullptr && root->val <= pre->val)
    		return false;       
        pre = root;
        if(root->right)
        	return isValidBSTCore(root->right,pre);
        return true;

    	}
};