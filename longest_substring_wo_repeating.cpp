#include <bits/stdc++.h>
using namespace std;

// return thr length of longest substring without character repitition
// brute force approach that takes TC of O(n^2) and SC of O(n)

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int len = 0, maxLen = 0;
    for(int i = 0; i < n; i++){
        unordered_map <int, int> mp;
        for(int j = i; j < n; j++){
            if(mp[s[j]] == 1) break;
            len = j - i + 1;
            maxLen = max(maxLen, len);
            mp[s[j]] = 1;
        }
    }
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
