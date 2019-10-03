题目描述:

Given a binary tree and a sum, find all root-to-leaf paths
 where each paths sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

1,递归解法
2,还可以用一个栈，根据树的先序遍历即深度优先搜索实现一个非递归解法
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {

        vector<vector<int>> ret;
    	if(root == nullptr)
    		return ret;

    	vector<int> temp;
    	pathSumCore(root,sum,ret,temp);
    	return ret;       
    }

    void pathSumCore(TreeNode *root,int sum,vector<vector<int>> &ret,vector<int> &temp)
    {
    	int val = root->val;
    	temp.push_back(val);
    	int curSum = sum - val;
    	if(curSum == 0 && root->left==nullptr && root->right==nullptr)
    	{
    		ret.push_back(temp);
    		temp.pop_back();
    		return;
    	}

    	if(root->left!=nullptr)
    		pathSumCore(root->left,curSum,ret,temp);
    	if(root->right!=nullptr)    		
    		pathSumCore(root->right,curSum,ret,temp);

    	temp.pop_back();
    	return;
    }
};