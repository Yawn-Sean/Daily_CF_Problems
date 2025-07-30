#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<i64> v(n), d(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i] >> p[i];
    }

    vector<int> ans;
    vector<int> consider(n, 1);

    for (int i = 0; i < n; i++) {
        if (!consider[i]) continue;
        ans.push_back(i + 1);

        int val = v[i];
        for (int j = i + 1; j < n; j++) {
            if (consider[j] && val > 0) {
                p[j] -= val;
                val--;
            }
        }

        i64 cur = 0;
        for (int j = i + 1; j < n; j++) {
            p[j] -= cur;
            if (consider[j] && p[j] < 0) {
                cur += d[j];
                consider[j] = 0;
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto& x : ans) {
        cout << x << " ";
    }
    return 0;
}
