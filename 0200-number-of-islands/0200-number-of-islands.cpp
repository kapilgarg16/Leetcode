class Solution {
public:

    void checkConne(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> & vis, int row, int clm){
    int b1[] = {1, 0, -1, 0};
    int b2[] = {0, 1, 0, -1};

    vis[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int x = i+b1[k];
        int y = j+b2[k];
        if(x>=0&&x<row&&y>=0&&y<clm&&vis[x][y]==false&&grid[x][y]=='1')
        {
           checkConne(x, y , grid, vis, row, clm);
        }
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int clm = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool> (clm, 0));
        int count = 0;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < clm ; j++){
                    if(vis[i][j] == false && grid[i][j] == '1'){
                        checkConne(i, j , grid, vis, row, clm);
                        count++;
                    }
                }
            }
        return count;
    }
};