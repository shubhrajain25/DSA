class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin() , arr.end());
    int n = arr.size();
        int mid = arr[(n-1)/2];
        vector<int>ans;
        vector<pair<int,int>>diff;

        for(int i = 0 ; i<n ; i++){
            diff.push_back({abs(arr[i]-mid) , arr[i]});
        }

        sort(diff.rbegin() , diff.rend());

        for(int i = 0 ; i<k ; i++){
            ans.push_back(diff[i].second);
        }


        return ans;
        
    }
};