class Solution {
public:
    string digitSum(string s, int k) {

        int n = s.size();

        if(n<=k) return s;

        int i = 0;
        string ans = "";
        while(i<n){
            
            int sum = 0;
            for(int j = i ; j<min(i+k , n ) ; j++){
             sum += s[j] - '0';

            }

            ans += to_string(sum);

            i+=k;
        }

        return digitSum(ans , k);
    }
};