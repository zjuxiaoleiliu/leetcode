题目描述:

Given a binary tree, return the bottom-up level order traversal of its nodes values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree{3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' 
signifies a path terminator where no node exists below.

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vector<vector<int>> ret ;
        if(root == nullptr)
          return ret;
      
        queue<TreeNode*> q;
        q.push(root);
        vector<int> currentLevel;

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                currentLevel.push_back(temp->val);
                q.pop();
                if(temp->left!=nullptr)
                    q.push(temp->left);
                if(temp->right!=nullptr)
                    q.push(temp->right);
            }
            ret.push_back(currentLevel);
            currentLevel.clear();
        }
        reverse(ret.begin(),ret.end());    
      return ret;        
    }
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vector<vector<int>> ret ;
        if(root == nullptr)
          return ret;
      
        queue<TreeNode*> q;
        q.push(root);
        int currentSize = 1;
        int nextSize = 0;
        vector<int> currentLevel;

        while(!q.empty())
        {
          TreeNode* temp = q.front();
          currentLevel.push_back(temp->val);
          q.pop();
          currentSize--;

          if(temp->left!=nullptr)
          {
            q.push(temp->left);
            nextSize++;
          }
          if(temp->right!=nullptr)
          {
            q.push(temp->right);
            nextSize++;
          }
          
          if(currentSize == 0)
          {             //或者按照原来的从上到下的层次遍历，最后再运用std::reverse函数
            ret.insert(ret.begin(),currentLevel);//每一次都插入在容器首
            currentLevel.clear();
            currentSize = nextSize;
            nextSize = 0;
          }
        }
      
      return ret;        
    }
};
