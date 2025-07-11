#include <iostream>
using namespace std;

// word-ladder 1
int wordladder(string startword, string targtword, vector<string>&wordlist){
    queue<pair<string,int>q,
    q.push({startword,1});

    unordered_set<int>st(wordlist.begin(),wordlist.end());
    st.erase(startword);

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetword) return steps;
        for (int i = 0; i < word.size(); i++){
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if (st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}



// word-ladder 2
unordered_map<string,int>mpp;
vector<vector<string>ans;
string str;

void dfs(string word, vector<string>&seq){
    if(word==str){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int steps = mpp[word];
    for (int i = 0; i < size; i++){
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++){
            word[i] = ch;
            if(mpp.find()!=mpp.end() && mpp[word]+1 == steps){
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }

}

vector<vector<int>> findladder(string beginword, string endword, vector<string>&wordlist){
    queue<string>q,
    q.push(beginword);
    str = beginword;
    
    unordered_set<int>st(wordlist.begin(),
    wordlist.end());
    st.erase(beginword);
    
    mpp[beginword]=1;
    
    int size = beginword.size();
    while(!q.empty()){
        string word = q.front();
        int step = mpp[word]
        q.pop();

        if(word==endword) break;
        for (int i = 0; i < size; i++){
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if (st.cound(word)){
                    q.push(word);
                    st.erase(word);
                    mpp[word] = step+1;
                }
            }
            word[i] = original;
        }
    }
    if(mpp.find(endword)!=mpp.end()){
        vector<string>seq;
        seq.push_back(endword);
        dfs(endword,seq);
    }
    return ans;
}