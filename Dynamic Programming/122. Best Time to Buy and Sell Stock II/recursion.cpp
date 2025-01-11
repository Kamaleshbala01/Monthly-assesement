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
    int solve(vector<int> &prices,int i,bool canBuy){
        // base case if i reach end return 0, no more call can be possible.
        if(i==prices.size()) return 0;
        
        // skip the value for both buy and sell state.
        int a = solve(prices,i+1,canBuy);
        if(canBuy){
            // calculate the value if the current element can buy if only no other element is buy in stake.
            a = max(a, solve(prices,i+1,false) - prices[i]);
         }else{
            // calculate the value if the current element can sell if only some element are buy before.
          a = max(a, solve(prices,i+1,true) + prices[i]);
         }
            

        return a;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices,0,true);
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<s.maxProfit(prices);
    return 0;
}