题目描述:

Clone an undirected graph. Each node in the graph 
contains alabeland a list of itsneighbors.

OJ s undirected graph serialization:
Nodes are labeled uniquely.

We use#as a separator for each node, and,as a separator 
for node label and each neighbor of the node.

As an example, consider the serialized graph{0,1,2# 1,2# 2,2}.

The graph has a total of three nodes, and therefore 
contains three parts as separated by#.

First node is labeled as0. Connect node0to both nodes1and2.
Second node is labeled as1. Connect node1to node2.
Third node is labeled as2. Connect node2to node2(itself), 
thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点
都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

提示：
节点数介于 1 到 100 之间。
无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
必须将给定节点的拷贝作为对克隆图的引用返回。
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


//DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(!node)
        	return nullptr;
        if(m.find(node)!=m.end())
        	return m[node];
        Node *root = new Node(node->val,{});
        m[node] = root;
        for(Node* neighbor : node->neighbors) 
        {
        	(root->neighbors).push_back(cloneGraph(neighbor));
        }
       
        return root;
    }
private:                      
    unordered_map<Node*, Node*> m;//这个映射即标识这个原结点到底有没有被复制过,如果进行过
};                                //复制操作的话，直接返回映射的值，避免重复的复制操作     


//BFS,这个更容易理解一些，由一个结点得到它能得到的下一层结点本身就是
//这个结点的所有的邻接结点
class Solution {
public:
    Node* cloneGraph(Node* node) {

    	if(!node)
            return nullptr;
        unordered_map<Node*, Node*> m;
        Node* root = new Node(node->val,{});
        m[node] = root;
        queue<Node*> q;
        q.push(node);//队列中加入的结点对应的是新复制的结点，但它这个新复制的
        while(!q.empty())   //结点的邻接表还没有确定
        {//这个循环中的操作主要做的是确定当前结点对应的复制结点的邻接表信息
        	Node* cur = q.front();
            q.pop();
            for(auto neighbor : cur->neighbors) 
            {
                if(m.find(neighbor) == m.end()) 
                {
                	m[neighbor] = new Node(neighbor->val,{});
                    q.push(neighbor);//队列中加入的是新复制的结点,但它的邻接表还没有确定
                }
                (m[cur]->neighbors).push_back(m[neighbor]);
            }
        }
        return root;
    }
};