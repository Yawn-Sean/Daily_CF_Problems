#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(2 * n);
    int total = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> vc[i];
        if (vc[i] == 1) ++total;
        else --total;
    }

    unordered_map<int, int> mp;
    int bias = 0;
    mp[0] = 2 * n;
    for (int i = 2 * n - 1; i >= n; --i) {
        if (vc[i] == 1) ++bias;
        else --bias;

        mp[bias] = i;
    }

    int bb = 0;
    int ans = mp[0];
    
    for (int i = 0; i < n; ++i) {
        if (vc[i] == 1) ++bb;
        else --bb;
        if (mp.count(-bb)) {
            ans = min(ans, mp[-bb] - i - 1);
        }
    }
    cout << ans << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
