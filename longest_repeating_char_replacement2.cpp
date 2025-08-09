#include<bits/stdc++.h>
using namespace std;

/* You are given a string s and an integer k. 
You can choose any character of the string and 
change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing
the same letter you can get after performing the above operations. */

// this is the better approach that uses a sliding window over the string
// TC is O(N + N)*26 and space is constant

int characterReplacement(string s, int k) {
    int n = s.size();
    int l = 0, r = 0, maxLen = 0, maxFreq = 0;
    vector <int> hash(26, 0);
    while(r < n){
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);
        while((r - l + 1 ) - maxFreq > k){
            hash[s[l] - 'A']--;
            maxFreq = 0;
            for(int i = 0; i < 26; i++) maxFreq = max(maxFreq, hash[i]);
            l++;
        }
        if((r - l + 1) - maxFreq <= k){
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
    }
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    // call
    cout << characterReplacement(s, k);
    return 0;
}