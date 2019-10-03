题目描述:

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies
 a path terminator where no node exists below.

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
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {

    	vector<TreeNode *> ret;
        if(n < 1)
            return ret;
    	ret = generateTreesCore(1,n);
    	return ret;       
    }
//思考递归函数接口设计成什么，接口的设计应该以方便我们的操作为准则(由于本题是需要建立结点，所以需要知道具体的结点元素值)
//先构造一个框架，边写边思考边完善
   vector<TreeNode *> generateTreesCore(int l,int r)
    {
    	vector<TreeNode*> ret;
    	if(l > r)
    	{
    		ret.push_back(nullptr);
    		return ret;
    	}
    	for(int i = l;i<=r;i++)//枚举根节点元素所有可能取值的情况
    	{   	
    		vector<TreeNode *> ret1 = generateTreesCore(l,i-1);
    		vector<TreeNode *> ret2 = generateTreesCore(i+1,r);
    		for(auto elem1:ret1)
    		{
    			for(auto elem2:ret2)
    			{
    				TreeNode * root = new TreeNode(i);
    				root->left = elem1;
    				root->right = elem2;
    				ret.push_back(root);
    			}
    		}
    	}
    	return ret;
    }
};