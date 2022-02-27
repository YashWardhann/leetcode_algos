class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1) return {0};
     
        vector<vector<int>> _EDGES(n); 
        
        // Build the adajency list 
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            _EDGES[u].push_back(v);
            _EDGES[v].push_back(u);
        }
        
        // Initialise the first layer of leave nodes 
        vector<int> leaveNodes;
        for (int i = 0; i < _EDGES.size(); ++i) {
            if (_EDGES[i].size() == 1) leaveNodes.push_back(i);
        }
        
        int remainingNodes = n; 
        while (remainingNodes > 2) {
            // Remove all the leave nodes 
            remainingNodes -= leaveNodes.size();
            vector<int> newLeaves;  
            while (leaveNodes.size() > 0) {
                int leaf = leaveNodes.back();
                leaveNodes.pop_back();
                
                // Get the neighbour of the leave node 
                int neighbour = _EDGES[leaf][0];
                
                // Remove the edge from the graph 
                _EDGES[neighbour].erase(std::remove(_EDGES[neighbour].begin(), _EDGES[neighbour].end(), leaf), _EDGES[neighbour].end());
                
                // Check if the parent is a leaf node 
                if (_EDGES[neighbour].size() == 1)  newLeaves.push_back(neighbour);
            }     
            // Reassign the new leaf nodes
            leaveNodes = newLeaves;
        }
        return leaveNodes;
    }
};
