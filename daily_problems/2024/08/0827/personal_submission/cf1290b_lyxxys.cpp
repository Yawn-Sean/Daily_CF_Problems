#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    vector <vector<int>> Pre(n+1, vector<int>(26));
    for (int i = 0; i < n; ++ i){
        int c = s[i]-'a';
        Pre[i+1] = Pre[i];
        Pre[i+1][c] += 1;
    }
    /*
        可以构造成不可拆分的输出 Yes, 否则输出 No
    */
    while (q--){
        int l, r;
        cin >> l >> r;
        -- l, -- r;
        if (s[l] != s[r] || l == r){
            cout << "Yes\n";
        } else {
            int c = 0;
            for (int i = 0; i < 26; ++ i){
                if (Pre[r+1][i]-Pre[l][i] > 0){
                    ++ c;
                }
            }
            cout << (c>2 ? "Yes\n" : "No\n");
        }
    }
}
