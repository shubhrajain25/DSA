class Solution {
public:

void dfs(vector<vector<int>>& isConnected , int row ,vector<int>& vis ){
    
    int m = isConnected[0].size();
    vis[row] =1;

   for(int i =0; i<m; i++){
            if(isConnected[row][i] == 1 && vis[i] == 0){
                 dfs( isConnected, i ,vis);
            }
   }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
           int m = isConnected.size();

     vector<int>vis(m , 0);
        int count = 0;


     for(int i=0; i<m; i++){
     
        if(vis[i] != 1){
            count++;
            dfs( isConnected , i , vis);
        }

     }

return count;



    }
};