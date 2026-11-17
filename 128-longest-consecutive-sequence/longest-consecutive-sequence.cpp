class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num :nums){
            st.insert(num);
        }
        int longest = 0;

        for(int i : st){
            int count= 1 ;
        int num = i;



            if(st.find(i-1)==st.end()){




                while(st.find(num+1) != st.end()){
                    count++;
                    num++;
                }


                 longest = max(longest, count);
            }
        }



        return longest;
    }
};