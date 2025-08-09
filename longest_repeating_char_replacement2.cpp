#include<bits/stdc++.h>
using namespace std;

/* You are given a string s and an integer k. 
You can choose any character of the string and 
change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing
the same letter you can get after performing the above operations. */

int characterReplacement(string s, int k) {
    int n = s.size(), maxLen = 0;
    
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