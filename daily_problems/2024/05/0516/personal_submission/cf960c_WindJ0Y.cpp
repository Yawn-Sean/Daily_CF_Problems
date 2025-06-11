#include <bits/stdc++.h>
using namespace std;

void work() {
    int X, d; cin >> X >> d;
    
    vector<long long> ans;

    int bcnt = 0;
    long long cur_num = 1;
    while (X) {
        if (X & 1) {
            for (int i = 0 ; i < bcnt; i ++) {
                ans.push_back(cur_num);
            }
            cur_num += d;
            ans.push_back(cur_num);
            cur_num += d;
        }
        bcnt ++;
        X >>= 1;
    }

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}