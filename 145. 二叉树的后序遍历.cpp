题目描述:

Given a binary tree, return the postorder traversal of its nodes values.
For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3

return[3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode *root) 
    {

    	vector<int> result;
    	if(root == nullptr)
    		return result;
    	stack<TreeNode*> s;
        TreeNode *cur;                       
        TreeNode *pre=NULL;                 
        s.push(root);
        while(!s.empty())
        {
        	cur=s.top();
            if((cur->left==NULL && cur->right==NULL) || (pre!=NULL && (pre==cur->left || pre==cur->right)))
            {
            	result.push_back(cur->val);  
                s.pop();
                pre=cur; 
            }
            else
            {
            	if(cur->right!=NULL)//当前节点还能向下增长加入子节点
                s.push(cur->right);
                if(cur->left!=NULL)    
                s.push(cur->left);
            }
        }

     return result;    
               
    }
};

