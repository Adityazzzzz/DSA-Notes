-+#include<iostream>
using namespace std;


bool isvalid(string &part){
    if(part.length()>1 && part[0]=='0') return false;
    int val = stoi(part);
    return val>=0 && val<=255;
}
string join(vector<string>&ds){
    return ds[0] + "." + ds[1] + "." + ds[2] + "." + ds[3];
}

void func(int index,vector<string>&ans,vector<string>&ds,string s){
    if(ds.size()==4){
        if(index==s.size()){
            ans.push_back(join(ds));
        }
    }

    for(int i=1;i<=3;i++){
        if(index+i > s.size()) break;
        string part = s.substr(index,i);

        if(isvalid(part)){
            ds.push_back(part);
            func(index+i,ans,ds,s);
            ds.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    vector<string>ans;
    vector<string>ds;
    func(0,ans,ds,s);
    return ans;
}
