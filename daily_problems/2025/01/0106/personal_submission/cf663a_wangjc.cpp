#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    string s;
    getline(cin, s);
    cin >> s;
    int Add = 0;
    int Sub = 0;
    for (auto i : s) {
        if (i == '+') {
            Add++;
        } else if (i == '-') {
            Sub++;
        }
    }
    int pp = s.find('=') + 2;
    int n = stoi(s.substr(pp));
    int mi = 1 + Add - Sub * n;

    int mx = n + Add * n - Sub;
    if (n >= mi && n <= mx) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
        return;
    }
    vector<int> pos(1 + Add);
    vector<int> neg(Sub);
    pos[0] = 1;
    int p1 = 1, p2 = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '+') {
            pos[p1++] = 1;
        } else if (s[i] == '-'){
            neg[p2++] = n;
        }
    }
    int tot = 0;
    for (auto i : pos) tot += i;
    for (auto i : neg) tot -= i;
    while (tot < n) {
        for (int i = 0; i < pos.size(); i++) {
            if (tot == n) break;
            pos[i] = min(n, n - tot + 1);
            tot += pos[i] - 1;
        }
        for (int i = 0; i < neg.size(); i++) {
            if (tot == n) break;
            if (n - tot >= n) {
                neg[i] = 1;
                tot += n - 1;
            } else {
                neg[i] = tot;
                tot += n - tot;
            }
        }
    }
    p1 = 1, p2 = 0;;
    string res;
    res += to_string(pos[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '?') {
            if (s[i - 2] == '+') {
                res.append(to_string(pos[p1++]));
            } else {
                res.append(to_string(neg[p2++]));
            }
        } else {
            res += s[i];
        }
    }
    cout << res << endl;
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
