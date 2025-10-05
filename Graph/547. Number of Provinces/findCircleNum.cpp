class Solution {
public:
    void dfs(int src, unordered_map<int,bool>& vis, vector<vector<int>>& isConnected){
        vis[src] = true;

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[src][i] && !vis[i]){
                dfs(i,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        unordered_map<int,bool> vis;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                count++;
            }
        }

        return count;
    }
};
