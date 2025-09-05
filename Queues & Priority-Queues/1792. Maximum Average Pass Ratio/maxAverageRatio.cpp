class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        auto gain = [](int pass, int total){
            return ((double)(pass+1)/(total+1)) - ((double)pass/total);
        };

        for(auto &c : classes){
            pq.push({gain(c[0],c[1]),{c[0], c[1]}});
        }

        while(extraStudents--){
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            pass++;
            total++;
            pq.push({gain(pass, total),{pass, total}});
        }

        double avg = 0.0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            avg += (double)pass/total;
        }

        return avg/classes.size();
    }
};
