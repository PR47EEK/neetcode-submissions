/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> umap;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(umap.find(node) != umap.end()) return umap[node];
        Node* newNode = new Node();
        newNode->val = node->val;
        umap[node] = newNode;
        for(auto x : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(x));
        }
        return newNode;
    }
};
