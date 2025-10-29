#include bits/stdc++.h  
using namespace std;
int minjumps(int idx,vector<int>&nums,vector<int>&dp){
    int n=nums.size()-1;
    if(idx==n)
    return 0;
    if(idx>n)
    return 1e9;
if(dp[idx]!=-1)
return dp[idx];
int minjump=1e9;
for(int jump=1;jump<=nums[idx];jump++){
    int jumpcost=minjumps(idx+jump,nums,dp);
    if(jumpcost!=1e9)
    minjump=min(minjump,1+jumpcost);
}return dp[idx]=minjump;
}int jumpgame(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    int ans=minjumps(0,nums,dp);
    return ans;
}