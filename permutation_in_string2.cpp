#include <bits/stdc++.h>
using namespace std;

/* Given two strings s1 and s2,
return true if s2 contains a permutation of s1,
or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2. */

// this is the optimal sliding window approach that takes O(m) TC and again, constant space

bool isFreqSame(vector<int> &a, vector<int> &b) {

    // helper function (can be done in main as well)
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if (n > m) return false;

    vector<int> freqCount(26, 0), freqWindow(26, 0);
    for (char c : s1) freqCount[c - 'a']++;

    for (int i = 0; i < n; i++) {
        freqWindow[s2[i] - 'a']++;
    }
    if (isFreqSame(freqWindow, freqCount)) return true;

    for (int i = n; i < m; i++) {
        freqWindow[s2[i] - 'a']++;
        freqWindow[s2[i - n] - 'a']--;
        if (isFreqSame(freqWindow, freqCount)) return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (checkInclusion(s1, s2) ? "true" : "false");
    return 0;
}
