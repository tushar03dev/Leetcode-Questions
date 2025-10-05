class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<char>>& grid, map<pair<int,int>,bool>& vis){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && !vis[{newX,newY}]){
            return true;
        } else return false;
    }
    void bfs(int srcX, int srcY, map<pair<int,int>,bool>& vis, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({srcX,srcY});
        vis[{srcX,srcY}] = true;

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int tempX = front.first;
            int tempY = front.second;

            int dx[] ={-1,1,0,0};
            int dy[] = {0,0,-1,1};

            for(int i = 0; i < 4; i++){
                int newX = tempX + dx[i];
                int newY = tempY +dy[i];
                if(isSafe(newX, newY,grid,vis)){
                    q.push({newX, newY});
                    vis[{newX, newY}] = true;
                }
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        map<pair<int,int>,bool> vis;
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if(!vis[{i,j}] && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
