#include <bits/stdc++.h>
using namespace std;

// return thr length of longest substring without character repitition
// optimal approach takes O(n) TC and constant O(256) SC 

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    vector <int> mp(256, -1);
    int l = 0, r = 0, maxLen = 0;
    while(r < n){
        if(mp[s[r]] != -1){
            if(mp[s[r]] >= l){
                l = mp[s[r]] + 1;
            }
        }
        int len = r - l + 1;
        maxLen = max(maxLen, len);
        mp[s[r]] = r;
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
