题目描述:

Given inorder and postorder traversal of a tree, construct the binary tree.

Note: 
You may assume that duplicates do not exist in the tree.


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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    	int m = inorder.size();
    	int n = postorder.size();
    	if(m!=n || m==0)
    		return nullptr;
    	return buildTreeCore(inorder,0,n-1,postorder,0,n-1);
        
    }

    TreeNode *buildTreeCore(vector<int> &inorder,int in_l,int in_r,vector<int> &postorder,int post_l,int post_r)
    {                                 //这里要注意malloc函数的返回值为void*类型，调用这个函数时我们要强制转换成我们需要的
    	TreeNode * root = new TreeNode(postorder[post_r]);//类型
    	root->left = nullptr;
    	root->right = nullptr;

    	int leftEnd = in_l;
    	while(leftEnd <= in_r)
    	{
    		if(inorder[leftEnd] == root->val)
    			break;
    		else
    			leftEnd++;
        }

        if(leftEnd>in_l)
        	root->left = buildTreeCore(inorder,in_l,leftEnd-1,postorder,post_l,post_l+leftEnd-in_l-1);
        if(in_r-in_l>leftEnd-in_l)
        	root->right = buildTreeCore(inorder,leftEnd+1,in_r,postorder,post_l+leftEnd-in_l,post_r-1);

        return root;

    }

    


};