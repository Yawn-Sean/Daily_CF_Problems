#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    int mi = n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) continue;
        mi = min(mi, c[i]);
        arr.push_back(c[i]);
    }
    for (int i = mi + 1; i >= 2; i--) {
        bool flag = true;
        for (int j : arr) {
            int re = j / (i - 1);
            int rem = j % (i - 1);
            if (rem > re) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cnt = 0;
            for (int j : arr) {
                if (j % i == 0)
                    cnt += j / i;
                else
                    cnt += j / i + 1;
            }
            cout << cnt << endl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}