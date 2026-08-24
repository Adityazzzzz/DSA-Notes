#include <iostream>
using namespace std;

int func(int day,int last,vector<vector<int>&arr,vector<vector<int>&dp){
    if(day==0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,arr[0][i]);
            }
        }
        return maxi;
    }
    
    if(dp[day][last] != -1) return dp[day][last];
    
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int score = arr[day][i] + func(day-1,i,arr,dp);
            maxi = max(maxi,score);
        }
    }
    return dp[day][last] = maxi;
}

// tabulation ---------------------------------------------------------------------------------------
int ninjatraining(int n,vector<vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(4,0));

    dp[0][0] = max(arr[0][1],arr[0][2]);
    dp[0][1] = max(arr[0][0],arr[0][2]);
    dp[0][2] = max(arr[0][0],arr[0][1]);
    dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            for(int task=0;task<3;task++){
                if(task != last){
                    int score = arr[day][task] + dp[day-1][task];
                    
                    dp[day][last] = max(dp[day][last],score);
                }
            }
        }
    }
    return dp[n-1][3];
}

// space optimization -----------------------------------------------------------------------------------
int ninjatraining(int n,vector<vector<int>&arr){
    vector<int>prev(4);

    prev[0] = max(arr[0][1],arr[0][2]);
    prev[1] = max(arr[0][0],arr[0][2]);
    prev[2] = max(arr[0][0],arr[0][1]);
    prev[3] = max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            for(int task=0;task<3;task++){
                if(task != last){
                    temp[last] = max(temp[last],arr[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}