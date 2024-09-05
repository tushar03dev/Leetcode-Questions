class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount =0;
        int tenCount=0;
        int twentyCount=0;
        for(auto x:bills){
            switch(x){
                case 5:{
                    fiveCount++;
                    break;
                }
                case 10:{
                    tenCount++;
                    if(fiveCount == 0){
                        return false;
                    } 
                    else{
                         fiveCount--;
                    }
                    break;
                }
                case 20:{
                    twentyCount++;
                    if( fiveCount ==0){
                        return false;
                    }
                    else if(tenCount ==0){
                        if(fiveCount >=3){
                            fiveCount -=3;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        fiveCount--;
                        tenCount--;
                    }
                    break;
                }
            }
        }
        return true;
    }
};
