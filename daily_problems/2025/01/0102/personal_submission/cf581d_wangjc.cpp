/*
    写的很丑陋的分类讨论
    有两种情况：
    1. 三个长方形并排放
    2. 一个大长方形放上面，下面两个等宽的长方形放一起
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    vector<vector<int>> p(3, vector<int>(3));
    for (int i = 0; i < 3; i++) cin >> p[i][0] >> p[i][1], p[i][2] = i;

    int area = p[0][0] * p[0][1] + p[1][0] * p[1][1] + p[2][0] * p[2][1];
    int l = sqrt(area);
    if (l * l != area) {
        cout << "-1\n";
        return;
    }

    if (p[0][0] < p[0][1]) swap(p[0][0], p[0][1]);
    if (p[1][0] < p[1][1]) swap(p[1][0], p[1][1]);
    if (p[2][0] < p[2][1] )swap(p[2][0], p[2][1]);

    sort(p.rbegin(), p.rend());

    vector<string> ans;
    if (p[0][0] < l) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < p[0][1]; i++) ans.push_back(string(l, 'A' + p[0][2]));

    if (p[1][0] == l) {
        for (int i = 0; i < p[1][1]; i++) ans.push_back(string(l, 'A' + p[1][2]));

        if (p[2][0] == l) {
            for (int i = 0; i < p[2][1]; i++) ans.push_back(string(l, 'A' + p[2][2]));
        } else {
            cout << "-1\n";
            return;
        }
    } else {
        // cerr << p[1][0] << " " << p[1][1] << " " << p[2][0] << " " << p[2][1] << "\n";
        if (p[1][0] == p[2][0] && p[1][0] == l - p[0][1] && p[1][1] + p[2][1] == l) {
            string cur = string(p[1][1], 'A' + p[1][2]) + string(p[2][1], 'A' + p[2][2]);
            for (int i = 0; i < p[1][0]; i++) ans.push_back(cur); 
        } else if (p[1][0] == p[2][1] && p[1][0] == l - p[0][1] && p[1][1] + p[2][0] == l) {
            string cur = string(p[1][1], 'A' + p[1][2]) + string(p[2][0], 'A' + p[2][2]);
            for (int i = 0; i < p[1][0]; i++) ans.push_back(cur); 
        } else if (p[1][1] == p[2][1] && p[1][1] == l - p[0][1] && p[1][0] + p[2][0] == l) {
            string cur = string(p[1][0], 'A' + p[1][2]) + string(p[2][0], 'A' + p[2][2]);
            for (int i = 0; i < p[1][1]; i++) ans.push_back(cur); 
        } else if (p[1][1] == p[2][0] && p[1][1] == l - p[0][1] && p[1][0] + p[2][1] == l) {
            string cur = string(p[1][0], 'A' + p[1][2]) + string(p[2][1], 'A' + p[2][2]);
            for (int i = 0; i < p[1][1]; i++) ans.push_back(cur); 
        } else {
            cout << "-1\n";
            return;
        }
    }
    cout << l << "\n";
    for (auto s : ans) {
        cout << s << "\n";
    }


}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
