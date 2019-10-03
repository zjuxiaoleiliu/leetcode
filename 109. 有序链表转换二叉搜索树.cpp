题目描述:

Given a singly linked list where elements are sorted 
in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        
        if(head==nullptr)
            return nullptr;   
        if(head->next==nullptr)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        if(head->next->next == nullptr)//主要是两个节点这种情况时，下面的操作pre等于nullptr
        {
            TreeNode *root = new TreeNode(head->val);
            root->right = new TreeNode(head->next->val);
            return root;

        }
           
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;//使用一个变量跟踪操作过程随时记录更新信息
           
        while(fast->next && fast->next->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        fast = slow->next;
        slow->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);          
        return root;
    }
       
};
