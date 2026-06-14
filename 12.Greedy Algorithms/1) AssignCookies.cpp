#include <iostream>
using namespace std;

int findContentChildren(vector<int>& student,vector<int>& cookie){
    sort(student.begin(),student.end());
    sort(cookie.begin(),cookie.end());

    int studentIndex = 0; 
    int cookieIndex = 0;  
    while (studentIndex < student.size() && cookieIndex < cookie.size()) {
        if (cookie[cookieIndex] >= student[studentIndex]) {
            studentIndex++; 
        }
        cookieIndex++; 
    }
    return studentIndex;
}