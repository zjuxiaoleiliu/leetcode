题目描述:

Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree andsum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path5->4->11->2which sum is 22.


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
    bool hasPathSum(TreeNode *root, int sum) {

    	if(root == nullptr)
    		return false;

    	int curSum = sum - root->val;  
    	int result = false;   //对于先序遍历最好显示的写出递归终止条件，它不像中序和后序遍历
    	if(curSum == 0 && root->left == nullptr && root->right == nullptr)//可以隐式包含
    		result = true;
    	if(!result)
    		result = hasPathSum(root->left,curSum);
    	if(!result)
    		result = hasPathSum(root->right,curSum);
    	return result;    
    }
};