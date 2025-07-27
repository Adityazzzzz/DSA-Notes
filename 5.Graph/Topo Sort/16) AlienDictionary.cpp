#include<iostream>
using namespace std;

vecor<int>toposort(int V,vector<int>adj[]){
    int degree[V]={0};
    for(int i=0;i<V;i++){
        for(auto it: adj[i]) degree[it]++;
    }

    queue<int>q;
    for(int i=0;i<V;i++){
        if(degree[i] == 0) q.push(i);
    }

    vector<int>ans;
    while(!q.empty()){
        int node = q.node();
        q.pop();
        ans.push_back(node);

        for(auto it:adj[node]){
            degree--;
            if(degree[it]==0) q.push.push(it);
        }
    }
    return ans;
}

string findorder(string dict[],int N,int k){
    vector<int>adj[k];
    for(int i=0;i<N-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];

        int len = min(s1.size(),s2.size());
        for(int ptr = 0;ptr<len;ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a'); // so that char becomes 0
                break; 
            }
        }
    }

    vector<int>ans = toposort(k,adj);
    string ans1 = "";
    for(auto it : ans){
        ans = ans + char(it+'a') //
    }
    return ans;
}