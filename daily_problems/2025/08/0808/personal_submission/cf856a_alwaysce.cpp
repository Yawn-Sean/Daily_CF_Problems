#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int MX = 1e6 + 1;
    vector<int> used(MX);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> ans;
        for (int i = 1; i < MX; i++) {
            if (!used[i]) {
                ans.push_back(i);

                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < j; k++) {
                        int val = abs(a[j] - a[k]) + i;
                        if (val < MX) {
                            used[val] = 1;
                        }
                    }
                }
            }
            if (ans.size() == n) break;
        }
        cout << "YES\n";
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
        for (int i = 1; i < MX; i++) {
            used[i] = 0; // reset for next test case
        }

    }
    return 0;
}
