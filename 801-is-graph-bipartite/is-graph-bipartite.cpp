class Solution {
public:

bool dfs(vector<vector<int>>& graph , vector<int>&colour , int paint , int node){
    colour[node] = paint;

    for(auto u : graph[node]){

        if(colour[u]==-1){
            if(!dfs(graph , colour , 1^paint , u)) return false;
        }
        else{
            if(colour[u]==paint) return false;
        }
    }
    return true;


}
    bool isBipartite(vector<vector<int>>& graph) {
        int n =  graph.size();
        vector<int>colour(n , -1);

        for(int i = 0 ; i<n ; i++){
            if(colour[i]==-1){
                if(!dfs(graph , colour , 0, i ))
                return false;
            
        }
        }
        return true;
    }
};