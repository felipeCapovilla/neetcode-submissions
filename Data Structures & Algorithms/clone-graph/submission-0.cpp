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
public:
    Node* cloneGraph(Node* node) {

        
        if(node==nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> hash;
        return dfs(node,hash);

        
    }

    Node* dfs(Node* node, unordered_map<Node*,Node*>& hash){
        if(node==nullptr){
            return nullptr;
        }

        if(hash.count(node)){
            return hash[node];
        }

        Node* copy = new Node(node->val);
        hash[node] = copy;

        for(Node* next_node : node->neighbors){
            copy->neighbors.push_back(dfs(next_node,hash));
        }

        return copy;
    }
};
