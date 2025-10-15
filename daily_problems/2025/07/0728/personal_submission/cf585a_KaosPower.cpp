#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> vs(n), ds(n), ps(n);
    for (int i = 0; i < n; i ++)
        cin >> vs[i] >> ds[i] >> ps[i];

    vector<char> to_decide(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i ++) {
        if (!to_decide[i]) {
            ans.emplace_back(i);
            int v = vs[i];

            for (int j = i + 1; j < n; j ++) {
                if (!to_decide[j] && v) {
                    ps[j] -= v;
                    v --;
                }
            }

            long long cur = 0;
            for (int j = i + 1; j < n; j ++) {
                ps[j] -= cur;
                if (!to_decide[j] && ps[j] < 0) {
                    to_decide[j] = 1;
                    cur += ds[j];
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto &x: ans) cout << x + 1 << ' ';

    return 0;
}
