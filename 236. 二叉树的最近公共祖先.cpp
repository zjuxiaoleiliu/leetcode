给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的
深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || !p || !q)
    		return nullptr;
    	vector<TreeNode *> path1;
        if(!findPath(root,path1,p))
        	return nullptr;
    	vector<TreeNode *> path2;
    	if(!findPath(root,path2,q))
    		return nullptr;
    	return getIntersectionNode(path1,path2);       
    }

    bool findPath(TreeNode *root,vector<TreeNode *> &path,TreeNode *target)
    {
    	if(root == nullptr)
    		return false;
    	if(root == target)//从底往上递进讨论
    	{
    		path.push_back(root);
    		return true;
    	}
    	path.push_back(root);
    	bool ret = findPath(root->left,path,target);
    	if(ret == true)
    		return true;
    	ret = findPath(root->right,path,target);
    	if(ret == true)
    		return true;
    	path.pop_back();
    	return false;

    }

    TreeNode *getIntersectionNode1(vector<TreeNode *> &path1, vector<TreeNode *> &path2) {

    	int num1 = path1.size();
    	int num2 = path2.size();
    	int index1 = num1-1;
    	int index2 = num2-1;
    	int diff = abs(num1-num2);
    	if(num1 < num2)
    		index2 = index2-diff;
    	else
    		index1 = index1-diff;
    	if(path1[index1] == path2[index2])
    		return path1[index1];
    	while(index1)
    	{
    		if(path1[index1-1] == path2[index2-1])
    			return path1[index1-1];
    		else
    		{
    			index1 = index1-1;
    			index2 = index2-1;
    		}
    	}
    	return nullptr;        
    }

    TreeNode *getIntersectionNode2(vector<TreeNode *> &path1, vector<TreeNode *> &path2) {

    	int num1 = path1.size();
    	int num2 = path2.size();
    	int n = min(num1,num2);
    	int index = 0;
    	for(;index < n-1;index++)
    	{
    		if(path1[index+1]!=path2[index+1])
    			return path1[index];
    	}
    	return path1[index];       
    }
};

//将p、q的公共父节点问题转化为找到一个节点node使得p、q分别位于node的左右子树中。
/**
注意p,q必然存在树内, 且所有节点的值唯一!!!
递归思想, 对以root为根的(子)树进行查找p和q, 如果root == null || p || q 直接返回root
表示对于当前树的查找已经完毕, 否则对左右子树进行查找, 根据左右子树的返回值判断:
1. 左右子树的返回值都不为null, 由于值唯一左右子树的返回值就是p和q, 此时root为LCA
2. 如果左右子树返回值只有一个不为null, 说明只有p和q存在与左或右子树中, 最先找到的那个节点为LCA
3. 左右子树返回值均为null, p和q均不在树中, 返回null
**/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root || root == p || root == q)
        	return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //在左边找不到目标
        if(!left)
            return right;
        //在右边找不到目标
        if(!right)
            return left; 
        return root;
    }
};