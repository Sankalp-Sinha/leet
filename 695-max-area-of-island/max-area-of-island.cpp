class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        vector<vector<int>>vis(rows,vector<int>(cols, 0));
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    q.push({i,j});
                    vis[i][j]=1;
                    int comp = 0;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        comp++;
                        for (int i = 0; i < 4; i++) {
                            int nrow = r + drow[i];
                            int ncol = c + dcol[i];
                            if (nrow >= 0 && nrow < rows && ncol >= 0 &&
                                ncol < cols && grid[nrow][ncol] == 1 &&
                                vis[nrow][ncol] == 0) {
                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    ans = max(ans, comp);
                }
            }
        }
        return ans;
    }
};