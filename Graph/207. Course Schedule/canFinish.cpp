class Solution {
public:
    vector<int> topoSort(int n, unordered_map<int,list<int>> adjList){
        queue<int> q;
        unordered_map<int,int> indegree;
        vector<int> topoSort;

        for(auto i : adjList){
            for(auto &nbr: i.second){
                indegree[nbr]++;
            }
        }

        for(int node = 0; node < n; node++){
            if(indegree[node] == 0) q.push(node);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            topoSort.push_back(front);

            for(auto &nbr : adjList[front]){
                indegree[nbr]--;

                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        return topoSort;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjList;
        for(auto &vec: prerequisites){
            int u = vec[0];
            int v = vec[1];

            adjList[v].push_back(u);
        }

        vector<int> ans = topoSort(numCourses, adjList);
        if(ans.size() == numCourses) return true;
        else return false;

    }
};
