#include <bits/stdc++.h>
using namespace std;

// brute force approach that might TLE for large strings

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int n = s.size(), m = p.size();
    if (m > n) return result;
    string sortedP = p;
    sort(sortedP.begin(), sortedP.end());
    for (int i = 0; i <= n - m; i++) {
        string sub = s.substr(i, m);
        sort(sub.begin(), sub.end());
        if (sub == sortedP) {
            result.push_back(i);
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
