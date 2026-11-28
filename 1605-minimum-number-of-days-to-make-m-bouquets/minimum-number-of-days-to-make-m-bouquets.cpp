class Solution {
public:

bool possible(vector<int>& bloomDay , int m , int k , int mid){
int count = 0 ;
int bou = 0;

for(int i = 0 ; i<bloomDay.size() ; i++){
    if(bloomDay[i]<=mid){
        count++;
    }
    else{
        bou+=count/k;
        count = 0;
    }

            

}
bou += count / k;

        return bou >= m;
    


}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0; 
        int high = 0;

        for(int i = 0 ; i<bloomDay.size() ; i++){
            low = min(low , bloomDay[i]);
            high = max(high , bloomDay[i]);
        }
 if((long long)m * k > bloomDay.size()) return -1;
         int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(possible(bloomDay , m , k , mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                    low = mid+1;
            }
        }
        return ans ; 
    }
};