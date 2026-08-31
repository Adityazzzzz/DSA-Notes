#include <iostream>
using namespace std;

int timer = 0;
unordered_map<string,int> time;
unordered_map<string,int> low;
unordered_map<string,string> parent;
unordered_set<string> arr;
vector<string> bridges;

void recordEvent(string type,string explanation){
    cout << "[EVENT: " << type << "] " << explanation << "\n";
}

void dfs(string u,string rootId,unordered_map<string,vector<string>>& adj){
    time[u] = low[u] = timer;
    timer++;
    int childrenCount = 0;

    recordEvent("VISIT_NODE","Discovered island " + u);

    for(string v : adj[u]){
        if(time.find(v) == time.end()){
            childrenCount++;
            parent[v] = u;
            
            recordEvent("INSPECT_EDGE_TREE","Inspecting unvisited neighbor " + v);
            
            dfs(v,rootId,adj);
            
            low[u] = min(low[u],low[v]);
            if(low[v] > time[u]){
                bridges.push_back(u + "-" + v);
                recordEvent("CLASSIFY_BRIDGE","Bridge found between " + u + " and " + v);
            }
        
            if(u != rootId && low[v] >= time[u]){
                arr.insert(u);
                recordEvent("CLASSIFY_ARTICULATION","Island " + u + " is an articulation point.");
            }
            
        } 
        else if(v != parent[u]){
            recordEvent("INSPECT_EDGE_BACK","Found back-connection to visited island " + v);
            low[u] = min(low[u],time[v]);
        }
    }

    if(u == rootId && childrenCount > 1){
        arr.insert(u);
        recordEvent("CLASSIFY_ARTICULATION","Root " + u + " is an articulation point(has " + to_string(childrenCount) + " children).");
    }
}

void runTarjan(unordered_map<string,vector<string>>& adj,vector<string>& group){
    for(auto it : group){
        if(time.find(it) == time.end()){
            parent[it] = "null";
            recordEvent("START_COMPONENT","Starting DFS at root " + it);
            dfs(it,it,adj);
        }
    }
}