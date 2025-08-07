#include<bits/stdc++.h>
using namespace std;

// Given two strings s and t, return the minimum window substring of s
//such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".
// This is brute force approach that takes O(N^2) TC and constant space

string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    int minLen = INT_MAX, start = -1;
    for (int i = 0; i <= n - m; i++) {
        vector<int> hash(256, 0);
        for (char ch : t) hash[ch]++;
        int count = 0;
        for (int j = i; j < n; j++) {
            if (hash[s[j]] > 0) count++;
            hash[s[j]]--;
            if (count == m) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                break;
            }
        }
    }
    return (start == -1) ? "" : s.substr(start, minLen);
}

int main(){
    string s, t;
    cin >> s >> t;
    // call
    cout << minWindow(s, t);
    return 0;
}