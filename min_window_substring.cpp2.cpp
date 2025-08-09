#include<bits/stdc++.h>
using namespace std;

// Given two strings s and t, return the minimum window substring of s
// such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string.
// This is the optimal approach that takes O(N) TC and a constant space
// using a sliding window and frequency counting array we can boil down to one pass

string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    if (m > n) return "";
    vector<int> hash(256, 0);
    for (char ch : t) hash[ch]++;
    int count = m;
    int l = 0, r = 0, minLen = INT_MAX, start = -1;
    while (r < n) {
        if (hash[s[r]] > 0) count--;
        hash[s[r]]--;
        r++;
        while (count == 0) {
            if (r - l < minLen) {
                minLen = r - l;
                start = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0) count++;
            l++;
        }
    }
    return (start == -1) ? "" : s.substr(start, minLen);
}


int main(){
    string s, t;
    cin >> s >> t;
    // call
    string ans = minWindow(s, t);
    cout << ans;
    return 0;
}