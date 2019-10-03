题目描述:
Given a binary tree, 返回 the level order traversal of its nodes values.
 (ie, from left to right, level by level).
For example:
Given binary tree{3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal,
 where '#' signifies a path terminator where no node exists below.

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
    vector<vector<int> > levelOrder(TreeNode *root) {

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
          {
            ret.push_back(currentLevel);
            currentLevel.clear();
            currentSize = nextSize;
            nextSize = 0;          

          }

        }
      
      return ret;
    }
};
