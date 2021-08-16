// Hari

class Solution {
public:
    // make a global map for copied graph, with the node and its neighbors
    unordered_map<Node*, Node*> copies;
    Node* cloneGraph(Node* node) {
        // very simple implementation of a complex question
        
        // node points to the current node traversed in original graph
        if(!node) return nullptr; // base
        
        if(copies.find(node) == copies.end()) {
            // node not found in copied graph. Add it
            copies[node] = new Node(node->val, {});
            
            for(Node* it: node->neighbors){
                copies[node]->neighbors.push_back(cloneGraph(it));
            }
        } 
        return copies[node];
    }
};
