class Solution {
public:

bool dfs(vector<vector<int>>& adj, int node, int dest, vector<int>& vis) {

        if(node == dest) return true;

        vis[node] = 1;

        for(int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            if(vis[neigh] == 0) {
                if(dfs(adj, neigh, dest, vis))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
    vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        return dfs(adj, source, destination, vis);
    }

};