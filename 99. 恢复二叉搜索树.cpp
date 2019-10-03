题目描述:

二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？

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
    void recoverTree(TreeNode *root) {

        if(root == nullptr)
    		return;
    	TreeNode *p1 = nullptr;
    	TreeNode *p2 = nullptr;
    	TreeNode *pre = nullptr;
        int cnt = 0;//由cnt我们可以得知总共发生异常的次数，及交换的是相邻还是不相邻的元素这个信息
    	recoverTreeCore(root,pre,p1,p2,cnt);
        if(p1!=nullptr && p2!=nullptr)
        {
        	int temp = p1->val;
        	p1->val = p2->val;
        	p2->val = temp; 
        } 

    }
        //查找两个满足条件的结点，成功找到了要及时终止查找的进行，返回返回
        //一个布尔类型标识是否查找成功
    void recoverTreeCore(TreeNode *root,TreeNode* &pre,TreeNode* &first,TreeNode * &second,int &cnt)
    {   
    	if(root->left!=nullptr)
            recoverTreeCore(root->left,pre,first,second,cnt);
    	if(cnt == 2)
    		return;
    	if(pre!=nullptr &&  pre->val > root->val)//出现异常时会发生的状况
    	{   cnt++;
    		if(first == nullptr)
    			first = pre;
    	    second = root;
        }
    	pre = root;        
    	if(cnt == 2)
    		return;
    	else
    	{
    		if(root->right!=nullptr)
                recoverTreeCore(root->right,pre,first,second,cnt);
    	}

    }


};


//节点交换分两种情况，一种是相邻节点，这种交换不破坏两节点与之外的大小性，只破坏
//两节点之间大小性。(这种情况下只有一种pre > cur的异常情况，我们得遍历完所有的结点
//才能说只有这一种异常情况，才能下结论，因此本题的特点不适合通常的查找类型的递归返回
//一个bool标志及时终止函数调用的情况)另一种是不相邻，这种破坏两节点分别与两边的节点
//(此时有两种pre>cur的异常情况)
//因此在第一次搜到一个不满足的节点后，要将第二个节点也赋指针，以考虑第一种情况
class Solution {
public:
void recoverTree(TreeNode *root) {

        if(!root || (!root->left && !root->right))
            return;   	
    	TreeNode *p1 = nullptr;
    	TreeNode *p2 = nullptr;
    	TreeNode *pre = nullptr;
    	recoverTreeCore(root,pre,p1,p2);
        if(p1 && p2)
        {
        	int temp = p1->val;
        	p1->val = p2->val;
        	p2->val = temp; 
        }
    }
     
    void recoverTreeCore(TreeNode *root,TreeNode* &pre,TreeNode* &first,TreeNode * &second)
    {   
    	if(root == nullptr)
            return;
        recoverTreeCore(root->left,pre,first,second);
    	if(pre!=nullptr &&  pre->val > root->val)//出现异常时发生的状态情形
    	{
    		if(first == nullptr)
    			first = pre;
    	    second = root;
        }
    	pre = root;        
       recoverTreeCore(root->right,pre,first,second);
    	
    }

};

