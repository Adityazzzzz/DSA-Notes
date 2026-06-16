#include<iostream>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    vector<int> st;
    for(auto it : asteroids){
        if(it>0){
            st.push_back(it);
        }
        else{
            while(!st.empty() && st.back() > 0 && st.back() < abs(it)){
                st.pop_back();
            }

            // same val condition
            if(!st.empty() && st.back() > 0 && st.back() == abs(it)){
                st.pop_back();
            }
            //only neg ele remaining
            else if(st.empty() || st.back() < 0){
                st.push_back(it);
            }
        }
    }

    return st;
}