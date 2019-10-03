题目描述:

Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//解法1：递归解法
class Solution {
public:
    int maxDepth(TreeNode *root) {
        
        if(!root) return 0;
        if(!root->left) 
            return maxDepth(root->right)+1;
        if(!root->right) 
            return maxDepth(root->left)+1;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};


//解法2：树的层次遍历

class Solution {
public:
    int maxDepth(TreeNode *root) {

        if(root==nullptr) 
            return 0;
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);        
        while(!q.empty())
        {
            depth++;
            int n = q.size();
            while(n--)  
            {
                TreeNode * currentNode =q.front();
                q.pop();
                if(currentNode->left!=nullptr)
                    q.push(currentNode->left);
                if(currentNode->right!=nullptr)
                    q.push(currentNode->right);        
            }
        }
        return depth;       
    }
};
class Solution {
public:
    int maxDepth(TreeNode *root) {

        if(root==nullptr) 
        	return 0;
        int depth=1;
        queue<TreeNode*> q;
        q.push(root);
        int currentSize = 1;
        int nextSize = 0;
        
        TreeNode * currentNode = nullptr;
        while(!q.empty())
        {
            //将层的更新放在前面，在确定栈非空，说明这一层还有元素
            if(currentSize == 0)//先进入循环时先判断再根据判断结果决定要进行的操作
            {
                currentSize = nextSize;
                nextSize = 0;
                depth++;
            }	

            currentNode=q.front();
            q.pop();
            currentSize--;

            if(currentNode->left!=nullptr)
            {
                q.push(currentNode->left);
                nextSize++;
            }

            if(currentNode->right!=nullptr)
            {
                q.push(currentNode->right);
                nextSize++;
            }
            
        }
        return depth;       
    }
};


