// submission link: https://codeforces.com/contest/1243/submission/271347479

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int check;
    cin >> check;
    while(check --){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pair<int, int>> ops;
        function<void(int, int)> op = [&] (int i, int j){
            swap(s[i], t[j]);
            ops.emplace_back(i + 1, j + 1);
        };

        bool flag = true;
        for (int i = 0; i < n; i ++) {
            if (s[i] == t[i]) continue;
            
            bool thisflg = true;
            for (int j = i + 1; j < n; j ++) {
                if (s[i] == s[j]) {
                    op(j, i);
                    thisflg = false;
                    break;
                }
            }
            if (thisflg) {
                for (int j = i + 1; j < n; j ++) {
                    if (s[i] == t[j]) {
                        op(i + 1, j);
                        op(i + 1, i);
                        thisflg = false;
                        break;
                    }
                }
            }
            if (thisflg) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            cout << ops.size() << endl;
            for (auto &[x, y] : ops) {
                cout << x << ' ' << y << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}