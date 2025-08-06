#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int n = s.size(), m = p.size();
    if (m > n) return result;
    vector<int> freqP(26, 0), freqWindow(26, 0);
    for (char ch : p) {
        freqP[ch - 'a']++;
    }
    for (int i = 0; i < m; i++) {
        freqWindow[s[i] - 'a']++;
    }
    if (freqP == freqWindow) result.push_back(0);
    for (int i = m; i < n; i++) {
        freqWindow[s[i] - 'a']++;
        freqWindow[s[i - m] - 'a']--;        
        if (freqWindow == freqP) {
            result.push_back(i - m + 1);
        }
    }
    return result;
}

int main(){
    string s, p;
    cin >> s >> p;;
    vector <int> res = findAnagrams(s, p);
    for(auto it : res){
        cout << it << ", ";
    }
    return 0;
}
