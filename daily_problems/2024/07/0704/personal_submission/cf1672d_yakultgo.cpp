#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> cnt;
    int i = n - 1, j = n - 1;
    while (j >= 0) {
        if (a[i] == b[j]) {
            i--;
            j--;
            continue;
        }
        if (b[j] == b[j + 1]) {
            cnt[b[j]]++;
            j--;
        } else if (cnt[a[i]]) {
            cnt[a[i]]--;
            i--;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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