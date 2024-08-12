#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 200'000;
int a[MXN];
int b[MXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int i = n - 1, j = n - 1;
        multiset<int> reserved;
        while (i >= 0) {
            while (j > 0 && b[j] == b[j - 1]) {
                reserved.insert(b[j--]);
            }
            if (j >= 0 && a[i] == b[j]) {
                i--;
                j--;
            } else {
                auto it = reserved.find(a[i]);
                if (it == reserved.end()) break;
                reserved.erase(it);
                i--;
            }
        }
        cout << (i >= 0 ? "NO" : "YES") << "\n";
    }
    return 0;
}

