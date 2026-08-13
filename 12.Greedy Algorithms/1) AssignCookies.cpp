#include <iostream>
using namespace std;

int findContentChildren(vector<int>& student,vector<int>& cookie){
    sort(student.begin(),student.end());
    sort(cookie.begin(),cookie.end());

    int sIdx = 0; 
    int cIdx = 0;  
    while(sIdx < student.size() && cIdx < cookie.size()){
        if(cookie[cIdx] >= student[sIdx]){
            sIdx++; 
        }
        cIdx++; 
    }
    return sIdx;
}