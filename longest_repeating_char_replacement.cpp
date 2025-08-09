#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size(), maxLen = 0;
    for(int i = 0; i < n; i++){
        vector <int> hash(26, 0);
        int maxFreq = 0;
        for(int j = i; j < n; j++){
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            int changes = (j - i + 1) - maxFreq;
            if(changes <= k) maxLen = max(maxLen, j - i + 1);
            else break;
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