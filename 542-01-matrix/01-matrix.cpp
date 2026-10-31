class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>>q;
        vector<vector<int>>ans(m , vector<int>(n , -1));

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};


        for(int i = 0 ; i<m ; i++){
            for(int j =0; j<n ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int px = p.first;
            int py = p.second;

            for(int k = 0 ;k<4 ; k++){
                int npx = px+ dx[k];
                int npy = py + dy[k];

                if(npx<0 || npx>=m || npy<0 || npy>=n ) continue;

                if(ans[npx][npy]==-1){
                    ans[npx][npy] = ans[px][py]+1;
                    q.push({npx , npy});
                }
            }

        }
        return ans;
    }
};