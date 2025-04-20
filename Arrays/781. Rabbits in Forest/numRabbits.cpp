class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int arr[1001] ={0};
        for(int answer : answers){
            arr[answer]++;
        }
        int ans = arr[0];
        cout<<ans<<endl;
        for(int i = 1; i < 1001;i++){
            if(arr[i] > 0){
                if(arr[i] > i+1){
                    if(arr[i] % (i+1) == 0){
                        ans += (i+1)*(arr[i]/(i+1));
                    } else{
                        ans += (i+1)*(arr[i]/(i+1) + 1);
                    }
                } else {
                    ans += i+1;
                }
                cout<<ans<<endl;
            }
        }
        return ans;
    }
};
