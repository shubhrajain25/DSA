class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>>adj(n);
        int mod =1e9 + 7;

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
        pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

                vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);


            pq.push({0 , 0});
              dist[0] = 0;
        ways[0] = 1;


        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            if(time>dist[node])continue;

            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;


                if(time + wt < dist[adjNode]) {

                    dist[adjNode] = time + wt;

                    ways[adjNode] = ways[node];

                    pq.push({time + wt, adjNode});
                }

                else if(time + wt == dist[adjNode]) {

                    ways[adjNode] =
                    (ways[adjNode] + ways[node]) % mod;
                }

            }
        }

        return ways[n-1];
    }
};