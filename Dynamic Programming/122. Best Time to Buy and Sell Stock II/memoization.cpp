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
    int solve(vector<int> &prices,int i,bool canBuy,vector<vector<int>>&dp){
        // base case if i reach end return 0, no more call can be possible.
        if(i==prices.size()) return 0;
        // if the current state is already stored in dp we just return the computed state value.
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        // skip the value for both buy and sell state.
        int a = solve(prices,i+1,canBuy,dp);
        if(canBuy){
            // calculate the value if the current element can buy if only no other element is buy in stake
            a = max(a, solve(prices,i+1,false,dp) - prices[i]);
         }else {
            // calculate the value if the current element can sell if only some element are buy before.
            a = max(a, solve(prices,i+1,true,dp) + prices[i]);
         }
        //Store the state and return the value.
        return dp[i][canBuy] = a;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,true,dp);
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(prices);
    return 0;
}