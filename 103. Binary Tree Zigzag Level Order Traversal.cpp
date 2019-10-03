题目描述:

Given a binary tree, return the zigzag level order traversal of its nodes values.
 (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree{3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

      vector<vector<int>> ret;
      if(root == nullptr)
        return ret;
      stack<TreeNode*> s[2];
      s[0].push(root);
      int flag = 0;
      vector<int> temp;
      int size = 1;
      while(!s[flag].empty())
      {
        TreeNode * cur = s[flag].top();
        temp.push_back(cur->val);
        if(flag==0)
        {
          if(cur->left!=nullptr)
            s[1-flag].push(cur->left);
          if(cur->right!=nullptr)
            s[1-flag].push(cur->right);
        }
        else
        {
          if(cur->right!=nullptr)
            s[1-flag].push(cur->right);
          if(cur->left!=nullptr)
            s[1-flag].push(cur->left);
        }

        s[flag].pop();
        size--;
        if(size==0)
        { 
          ret.push_back(temp);
          flag = 1-flag;
          size = s[flag].size();
          temp.clear();
        }

      }
    
    return ret;
        
    }
};
