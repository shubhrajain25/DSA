class Solution {
public:

void dfs(int node , vector<vector<int>>& graph , vector<int>& path , vector<vector<int>>& ans){
    path.push_back(node);

    if(node == graph.size() - 1) {
            ans.push_back(path);
        }
        else{
            for(auto u: graph[node]){
                dfs(u , graph , path , ans);
            }
        }
        path.pop_back();

}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path ;
         vector<vector<int>>ans;

         dfs(0 , graph , path , ans);
         return ans;
    }
};