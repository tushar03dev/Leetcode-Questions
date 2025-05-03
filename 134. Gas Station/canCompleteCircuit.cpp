class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplus = 0;
        int surplus = 0;
        int index = 0;

        for(int i = 0; i < gas.size(); i++){
            totalSurplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                index = i + 1;
                surplus = 0;
            }
        }

        return totalSurplus < 0 ? -1 : index;
     
    }
};
