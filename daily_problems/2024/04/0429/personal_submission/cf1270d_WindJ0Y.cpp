#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, k; cin >> n >> k;

    map<int, int> cnt;
    for (int i = 0; i <= k; i++) {
        cout << "?";
        for (int j = 0; j <= k; j++) {
            if (i == j) {
                continue;
            }
            cout << " " << j + 1;
        }
        cout << endl;
        int pos, val; cin >> pos >> val;
        cnt[val] ++;
    }

    int ans = cnt.rbegin()->second;

    cout << "! " << ans << endl;
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