给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
方法1：递归解决方案
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(!root) 
            return 0;
        if(!root->left) 
            return minDepth(root->right)+1;
        if(!root->right) 
            return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
方法2：利用二叉树的层次遍历的思想，使用一个辅助的队列进行层次遍历，遇到给定的触发情况时停止遍历，返回结果

#include<queue>

class Solution {
public:
    int run(TreeNode *root) {
       
        if(root==nullptr) 
        	return 0;

        int depth=1;
        queue<TreeNode*> temp;
        temp.push(root);
        int currentSize = 1;
        int nextSize = 0;
        
        TreeNode * currentNode;
        while(!temp.empty())
        {
            currentNode=temp.front();
            temp.pop();
            currentSize--;//处理完当前层的一个结点后触发当前层要出来的结点个数-1操作

            if(currentNode->left==nullptr && currentNode->right==nullptr)
                return depth;

            if(currentNode->left!=nullptr)
            {
                temp.push(currentNode->left);
                nextSize++;
            }

            if(currentNode->right!=nullptr)
            {
                temp.push(currentNode->right);
                nextSize++;
            }

            if (currentSize==0)//当前层的最后一个结点已处理完毕
                {
                currentSize = nextSize;
                nextSize = 0;
                depth++;
            }
        }
 
    }
};

