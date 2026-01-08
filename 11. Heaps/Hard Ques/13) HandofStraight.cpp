#include <iostream>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand,int size){
        int n = hand.size();
        if(n % size != 0) return false;

        map<int,int> mpp;
        for(int &it : hand){
            mpp[it]++;
        }

        while(!mpp.empty()){
            int curr = mpp.begin()->first;

            for(int i = 0; i < size; i++){
                if(mpp[curr + i] == 0) return false;
                mpp[curr + i]--;
                
                if(mpp[curr + i] == 0){
                    mpp.erase(curr + i);
                }
            }
        }
        return true;
    }
};