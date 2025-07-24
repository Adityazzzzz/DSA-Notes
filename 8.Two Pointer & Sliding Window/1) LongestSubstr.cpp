#include<bits/stdc++.h>
using namespace std;

// longest substr withut repeating char

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int maxLen = 0, l = 0;
    
    for (int r = 0; r < s.length(); r++) {
        if (m.count(s[r]) && m[s[r]] >= l)l = m[s[r]] + 1;
        m[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
