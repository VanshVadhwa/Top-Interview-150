class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 
        int start = 0;
        int totalGas = 0;
        int currentGas = 0;

        for(int i=0;i<n;i++) {
            int gain = gas[i]-cost[i];
            currentGas += gain;
            totalGas += gain;

            if(currentGas < 0) {
                currentGas = 0;
                start = i+1;
            }
        }

        return totalGas < 0 ? -1 : start;
    }
};
