class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

int row  = matrix.size();
        int col = matrix[0].size();


        int low = 0;
        int high = row-1;
        int isrow = -1;

        while(low <= high){

            int mid = (low + high)/2;


            if(matrix[mid][0] <= target && matrix[mid][col-1] >= target){
                 isrow = mid;
                 break;
            }
            else if( matrix[mid][0] > target && matrix[mid][col-1] > target ){


                high = mid -1;
            }else if( matrix[mid][0] < target && matrix[mid][col-1] < target){


                low = mid+1;
            }



        }



        if(isrow != -1){
          
          int l = 0;
          int h = col-1;


          while(l<= h){

            int mid = (l + h)/2;


            if(matrix[isrow][mid] == target){
                return true;
            }
            else if(matrix[isrow][mid] > target){

            h = mid -1;
            }else {
                l = mid+1;
            }



          }

            














        }



return false;
    }
};