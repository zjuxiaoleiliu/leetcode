给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，
你将如何优化 kthSmallest 函数？


提示1：
Try to utilize the property of a BST.
提示2：
Try in-order traversal.( Credits to @chan13）
提示3：
What if you could modify the BST node s structure?
提示4：
The optimal runtime complexity is O(height of BST).


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

    	if(root == nullptr || k <= 0)
    		return INT_MAX;
    	TreeNode *ret = nullptr;
    	kthSmallestCore(root, k, ret);
    	if(ret != nullptr)
    		return ret->val;
    	else
    		return INT_MAX;       
    }
    void kthSmallestCore(TreeNode* root, int &k,TreeNode* &ret)
    {
    	if(root->left)
    	{
    		kthSmallestCore(root->left, k, ret);
    		if(k == 0)
    			return;
    	}
    	ret = root;
    	k--;
    	if(k == 0)
    		return;
    	if(root->right)
    		kthSmallestCore(root->right, k, ret);
    }
};

