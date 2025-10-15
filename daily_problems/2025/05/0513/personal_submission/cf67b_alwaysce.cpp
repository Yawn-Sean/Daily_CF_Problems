#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        vector<int> nans;

        for (auto&x: ans) {
            if (cnt == b[i]) {
                nans.push_back(i);
                cnt++;
            }
            nans.push_back(x);
            cnt += (x >= (i + k));
        }

        if (cnt == b[i]) {
            nans.push_back(i);
        }
        swap(ans, nans);
    }

    for (auto& x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
