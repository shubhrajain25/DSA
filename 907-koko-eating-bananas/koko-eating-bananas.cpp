class Solution {
public:

bool check(vector<int>& piles , int h , int mid){
    int n = piles.size();

    long long hours = 0;

    for(int i = 0 ; i<n ; i++){
            hours += piles[i] / mid;

        if(piles[i] % mid != 0) {
            hours++;
        }

        if(hours > h) return false;
    }


    

    return hours<=h;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = 0;
        int n = piles.size();
        for(int i = 0; i<n ; i++){
            high = max(high , piles[i]);
            
        }

            int ans = high ;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(check(piles , h , mid)){
                    ans = mid;
                    high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};