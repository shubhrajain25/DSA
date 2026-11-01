class Solution {
public:

bool dfs(int node , vector<vector<int>>& adj , vector<int>& vis ){
    
    
    vis[node] = 1;

    for(auto u : adj[node] ){
        if(vis[u]==0){
        if(dfs(u , adj, vis)==false){
            return false;
        }
        }
        else if(vis[u]==1) return false;

    }
    vis[node]= 2;
    return true;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

    vector<vector<int>> adj(numCourses);
    vector<int>visited(numCourses , 0);

     for (int i = 0; i < prerequisites.size(); i++) {
            int parent = prerequisites[i][1];
            int child = prerequisites[i][0];

            adj[parent].push_back(child);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};