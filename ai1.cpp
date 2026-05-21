#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,float>mpp;
    mpp["Yes"]=0.8;
    mpp["NO"]=0.2;

    string cloudy = "Yes";
    cout<<"P(Rain=Yes | cloudy=Yes)"<<mpp[cloudy]<<endl;

    return 0;
}