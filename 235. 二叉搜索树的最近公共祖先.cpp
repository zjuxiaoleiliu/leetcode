给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的
深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]



 

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 
因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//方法1：循环解法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    	if(root == nullptr)
    		return nullptr;
    	if(p == q)
    		return p;
    	TreeNode *pp = root;
    	int minVal = min(p->val,q->val);
    	int maxVal = max(p->val,q->val);
    	while(pp!=nullptr)
    	{
    		if(pp->val < minVal)//通过举例子找出规律，将向导指针调整到最近公共祖先节点所在的那一分支子树书上
    			pp = pp->right;
    		else if(pp->val > maxVal)
    			pp = pp->left;
    		else
    			return pp;
    	}
    	return nullptr;        
    }
};

//方法2：递归解法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    	if(!root || !p ||!q)
    		return nullptr;
    	TreeNode *pp = root;
    	int minVal = min(p->val,q->val);
    	int maxVal = max(p->val,q->val);    	
		if(pp->val < minVal)
			return lowestCommonAncestor(pp->right,p,q);//将向导指针调整到最近公共祖先所在的子树那个分支上
		else if(pp->val > maxVal)
			return lowestCommonAncestor(pp->left,p,q);
		else
			return pp;
    	       
    }
};