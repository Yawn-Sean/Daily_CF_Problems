#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    ranges::sort(indices, [&](int x, int y) {
        return a[x] > a[y];
    });
    string ans(n, ' ');
    ans[indices[0]] = 'B';
    for (int i = 1; i < n; i++) {
        int j = indices[i];
        bool can_move_to_loss = false;
        for (int d = a[j]; d < n; d += a[j]) {
            if (j + d < n && ans[j + d] == 'B') {
                can_move_to_loss = true;
                break;
            }
            if (j - d >= 0 && ans[j - d] == 'B') {
                can_move_to_loss = true;
                break;
            }
        }
        if (can_move_to_loss) {
            ans[j] = 'A';
        } else {
            ans[j] = 'B';
        }
    }
    cout << ans << "\n";
    return 0;
}

