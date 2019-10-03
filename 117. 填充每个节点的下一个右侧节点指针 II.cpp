题目描述:

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? 
Would your previous solution still work?

Note:

You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


  o
/  \  
O   O

方法1：最暴力的方法
class Solution {
public:
    Node * connect(Node *root) {

      if(root == nullptr)
        return nullptr;
      root->next = nullptr;
      connectCore(root);
      return root;      
    }

    void connectCore(Node*root)//最暴力的方法
    {
      if(root->left == nullptr && root->right == nullptr)
        return ;

      if(root->left!=nullptr && root->right!=nullptr)
        root->left->next = root->right;
      
      Node * theNode = nullptr;
      if(root->right!=nullptr)
        theNode = root->right;
      else
        theNode = root->left;

      if(root->next!=nullptr)//抽象出来的公共操作，公用代码，使得代码简洁
      {
        Node* cur = root->next;
        while(cur!=nullptr)
        {
          if(cur->left!=nullptr)
          {
            theNode->next = cur->left;
            break;
          }
          if(cur->right!=nullptr)
          {
            theNode->next = cur->right;
            break;
          }
          cur = cur->next;
        }
        if(cur == nullptr)
          theNode->next = nullptr;            
      }
      else
        theNode->next = nullptr;

      if(root->right!=nullptr)
        connectCore(root->right);//这里调用时要注意要先连接最右边的
      if(root->left!=nullptr)
        connectCore(root->left);

    }
};


方法2：设置两个指针，分别指向当前层的当前位置，下一层的当前位置
方法2:为了巧妙的利用尾指针连接的思想，这里使用一个下一层行头结点的思想，无法连接(因为空结点无法连接)

class Solution {
public:
    Node *connect(Node *root) {
        
      Node *first = root;
      while(first!=nullptr)
      {
        Node nextLevelHeadNode(-1);
        Node * pre = & nextLevelHeadNode;//有了头结点，我们现在的连接操作变得简单起来
                                         //还有一个好处是我们可以一次遍历使得处理完当前层的当前结点的
        for(auto p=first;p!=nullptr;p=p->next) //利用价值用完
        {
          if(p->left!=nullptr)
            {
              pre->next = p->left;
              pre = pre->next;
            }
            if(p->right!=nullptr)
            {
              pre->next = p->right;
              pre = pre->next;
            }

        }
        first = nextLevelHeadNode.next;
        nextLevelHeadNode.next = nullptr;
      }
      return root;
          
    }

};


方法3：就是采用队列层次遍历的方法