#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 5);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    vector<pair<int, int>> ji, ou;
    for (int i = 1; i <= n; i++) {
        if (i & 1) ji.push_back({nums[i], i});
        else ou.push_back({nums[i], i});
    }
    sort(ji.begin(), ji.end(), greater<pair<int, int>>());
    sort(ou.begin(), ou.end(), greater<pair<int, int>>());
    int j = 0, o = 0;
    for (int i = 1; i <= k; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            if (ji[j].first >= ou[k - 1 - j].first) {
                cout << ji[j].second << endl;
                j++;
            }
            else {
                cout << ou[o].second << endl;
                o++;
            }
        }
        else {
            cout << ou[o].second << endl;
            o++;
        }
        int check;
        cin >> check;
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}