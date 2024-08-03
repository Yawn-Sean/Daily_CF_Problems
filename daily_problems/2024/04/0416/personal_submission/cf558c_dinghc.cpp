#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 100000;
int a[MXN + 1]{};
int freq[MXN + 1]{};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int q = a[i];
        while (q) {
            freq[q]++;
            q >>= 1;
        }
    }

    int prefix;
    for (int i = MXN; i > 0; i--) {
        if (freq[i] == n) {
            prefix = i;
            break;
        }
    }

    int ans = 0;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int shft = __builtin_clz(prefix) - __builtin_clz(a[i]);
        int v = a[i] & ((1 << shft) - 1);
        if (v != 0) {
            ans += 32 - __builtin_clz(v);
            shft -= 32 - __builtin_clz(v);
        }
        b[i] = shft;
    }

    ranges::sort(b);

    for (auto& x : b) {
        ans += abs(x - b[n / 2]);
    }

    cout << ans << "\n";

    return 0;
}

