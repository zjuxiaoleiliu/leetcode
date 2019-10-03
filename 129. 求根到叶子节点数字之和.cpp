题目描述：

Given a binary tree containing digits from0-9only, 
each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.

Return the sum = 12 + 13 =25.

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
    int sumNumbers(TreeNode *root) {
        
        if(root==nullptr)
            return 0;
        int sum = 0;
        int preSum = 0;
        sumNumbersCore(root,0,sum);
        return sum;      
    }
    void sumNumbersCore(TreeNode *root,int preSum,int & sum)
    {
        int curSum = 10*preSum +root->val;
        if(root->left==nullptr && root->right==nullptr)
        {
            sum+=curSum;
            return;
        }
        if(root->left!=nullptr)
            sumNumbersCore(root->left,curSum,sum);
        if(root->right!=nullptr)
            sumNumbersCore(root->right,curSum,sum); 
    }
};