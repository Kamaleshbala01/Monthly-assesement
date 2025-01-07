// It is an updated version of buy and sell stoclk III 
// in buy and sell stoclk III we are allowed to make transaction atmost 2 times but here we can make tansaction atmost k times;

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
    int solve(int i,int k,bool canBuy,vector<int>&prices,int sellCnt){

        // base case if the sell count is more the k or i reach end return 0, no more call can be possible.
        if(sellCnt>=k || i == prices.size()) return 0;

        // skip the value for both buy and sell state.
        int skip = solve(i+1,k,canBuy,prices,sellCnt);

        if(canBuy){
            // calculate the value if the current element can buy if only no other element is buy in stake.
           int buy = -prices[i] + solve(i+1,k,false,prices,sellCnt);
           return  max(buy,skip);
        }else {
             // calculate the value if the current element can sell if only some element are buy before.
            int sell = prices[i] + solve(i+1,k,true,prices,sellCnt+1);
            return  max(sell,skip);
        }

    }
    int maxProfit(int k,vector<int>& prices) {
        return solve(0,k,true,prices,0);
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int k = 4;
    cout<<s.maxProfit(k,prices);
    return 0;
}