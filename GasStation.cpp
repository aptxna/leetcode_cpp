/**
 * Gas Station
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
 * You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * Note:
 * The solution is guaranteed to be unique.
 * 参考：
 * http://fisherlei.blogspot.com/2013/11/leetcode-gas-station-solution.html
 */

class GasStation {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> diff(gas.size(), 0);
        for (int i=0; i<gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
        }
        
        int sum = 0, leftgas = 0, startnode = 0;
        
        for (int i=0; i<gas.size(); i++) {
            leftgas += diff[i];
            sum += diff[i];
            if (sum < 0) {
                startnode = i+1;
                sum = 0;
            }
        }
        
        if (leftgas < 0)
            return -1;
        else
            return startnode;
    }
};