

bool scheduleCourse1(int V,vector<pair<int,int>>&data){
    vector<int>adj[]
    for(auto it:data){
        adj[it.firsdt].push_back(it.second);
    }

    // topo sort
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
    // for checking if there exists a cycle or not
    if(ans.size() == V) return true;
    else return false;
}