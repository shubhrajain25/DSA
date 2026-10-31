class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
            int n = grid[0].size();

        int count = 0;
        int fresh = 0;
        bool rotten = false;

        queue<pair<int , int>>q;
        vector<int>dx = {-1 , +1, 0 ,0};
        vector<int>dy = {0, 0 , +1 , -1};

        for(int i = 0 ; i<m ; i++){
            for(int j  =0 ; j<n ; j++){
                if(grid[i][j] == 2) q.push({i , j});

                else if(grid[i][j]==1) fresh++;

            }
            
        }
        if(fresh==0) return 0;

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int z=0 ; z<size ; z++){
                pair<int , int>p = q.front();
                q.pop();

                int px = p.first;
                int py = p.second;

                for(int k=0 ; k<4 ; k++){
                    int npx = px+dx[k];
                    int npy  = py+dy[k];

                    if(npx>=0 && npy>=0 && npx<m && npy< n &&  grid[npx][npy]==1){
                       grid[npx][npy] = 2;
                       fresh--;
                       
                        rotten = true;
                        q.push({npx , npy});
                    }
                }
            }

        if(rotten) count++;

        }
        if(fresh>0) return -1;

        return count;


    }
};