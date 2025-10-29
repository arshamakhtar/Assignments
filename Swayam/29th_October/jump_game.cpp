#include bits/stdc++.h>
using namespace std;
bool jump(int idx,vector<int>&n,vector<int>&dp){
    int n=nums.size()-1;
    if(idx==n)
    return true;
if(dp[idx]!=-1)
return dp[idx];
int maxjump=0;
for(int jump=1;jump<=maxjump;jump++){
    if(jump(idx+jump,n,dp))
    return dp[idx]= true;
}return dp[idx]=false;

}bool canjump(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return jump(0,nums,dp);
}