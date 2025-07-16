class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> budget;
        int n=gas.size();

        int max_ind = 0;
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            int ratio=gas[i]+1;
            if(cost[i]!=0){
                ratio = gas[i] / cost[i];
            }
            budget.push_back(ratio);
            if (ratio > maxx) {
                maxx = ratio;
                max_ind = i;
            }
        }

        for (int j=max_ind;j<max_ind+n;j++) {
            bool flag=false;
            int m = n;
            int i=j%n;
            int gass=gas[i];
            i++;
            while (m--) {
                if(gass-cost[(i-1)%n]<0){
                    j+=(n-m)-1;
                    flag=true;
                    break;
                }else{
                    gass+=(gas[i%n]-cost[(i-1)%n]);
                }
                i++;
            }
            if(!flag){
                return j%n;
            }
        }
        return -1;
    }
};
