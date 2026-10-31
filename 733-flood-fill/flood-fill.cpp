class Solution {
public:

void dfs(vector<vector<int>>&image , int sr, int sc , int currcolor , int color){

    int m = image.size();
    int n=  image[0].size();

    if(sr<0|| sr>=m || sc<0 || sc>=n || image[sr][sc]!=currcolor) return ;

    image[sr][sc]=color;
    dfs(image , sr+1, sc , currcolor , color);
     dfs(image , sr, sc-1 , currcolor , color);
      dfs(image , sr-1, sc, currcolor , color);
       dfs(image , sr, sc+1 , currcolor , color);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int m = image.size();
    int n=  image[0].size();


 if (image[sr][sc] != color) {
            dfs(image, sr, sc, image[sr][sc], color);
        }

        return image;
    }
};