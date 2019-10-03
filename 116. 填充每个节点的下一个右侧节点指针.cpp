题目描述:

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate(填充) each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set toNULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
public:
    Node *connect(Node *root) 
    {
      if(root == nullptr)
        return nullptr;
      root->next = nullptr;
      return connectCore(root);        
    }

    Node* connectCore(Node*root)//这个方法是针对完美二叉树的解决方案
    {                                  //稍作修改仍然可以作为一般的二叉树的解决方案

      if(root->left!=nullptr)
      {
        root->left->next = root->right;
        if(root->next!=nullptr)
          root->right->next = root->next->left;
        else
          root->right->next = nullptr;

        root->left = connectCore(root->left);
        root->right = connectCore(root->right);
      }
      return root;
    }
};    