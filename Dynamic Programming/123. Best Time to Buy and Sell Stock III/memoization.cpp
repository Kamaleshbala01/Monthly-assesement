#include <complex> 
#include <queue> 
#include <set> 
#include <unordered_set> 
#include <list> 
#include <chrono> 
#include <random> 
#include <iostream> 
#include <map>
#include <algorithm> 
#include <cmath> 
#include <string> 
#include <vector> 
#include <unordered_map> 
#include <stack> 
#include <iomanip> 
#include <fstream> 

using namespace std;

class Solution {
public:
    int solve(int i,bool canBuy,vector<int>&prices,int sellCnt,vector<vector<vector<int>>>&dp){
        // base case if the sell count is more the 2 or i reach end return 0, no more call can be possible.
        if(sellCnt==2 || i == prices.size()) return 0;

        // if the current state is already stored in dp we just return the computed state value.

        if(dp[i][sellCnt][canBuy]!=-1) return dp[i][sellCnt][canBuy];

        // skip the value for both buy and sell state.
        int skip = solve(i+1,canBuy,prices,sellCnt,dp);
        if(canBuy){
            // calculate the value if the current element can buy if only no other element is buy in stake
           int buy = -prices[i] + solve(i+1,false,prices,sellCnt,dp);
           // store the value in dp and return.
           return dp[i][sellCnt][canBuy] = max(buy,skip);
        }else {
            // calculate the value if the current element can sell if only some element are buy before.
            int sell = prices[i] + solve(i+1,true,prices,sellCnt+1,dp);
            // store the value in dp and return.
            return dp[i][sellCnt][canBuy] = max(sell,skip);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0,true,prices,0,dp);
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(prices);
    return 0;
}