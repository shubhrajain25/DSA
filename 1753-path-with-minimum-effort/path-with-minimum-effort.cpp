class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();


        vector<vector<int>>dis( n , vector<int>(m , INT_MAX));
        dis[0][0] = 0;

        //effort , row , column

        priority_queue<
        tuple<int , int , int> ,
        vector<tuple<int , int , int>>, //pq ke andar vector
        greater<tuple<int , int , int>> //min heap
        >pq;


        pq.push({0,0,0});

        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};


        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int effort = get<0>(it);
            int row = get<1>(it);
            int col = get<2>(it);


            if(effort>dis[row][col]) continue; //dis mai achi value hai , effort badha aa rha hai toh kuch nhi karege


            if(row == n-1 && col ==m-1) return effort;



            for(int i = 0 ; i<4 ; i++){
                int nr  = row+ dr[i];
                int nc = col + dc[i];


                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int diff = abs(
                        heights[nr][nc] - heights[row][col]
                    );

                    int newEffort = max(effort , diff);

                    if (newEffort < dis[nr][nc]) {

                        dis[nr][nc] = newEffort;

                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }

    return 0;


    }
};