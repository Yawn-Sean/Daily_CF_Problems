#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k,x;
    cin >> n >> k >> x;

    vector<int> freq(1025), new_freq(1025, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++freq[a];
    }

    while (k--) {
        int left = 0;
        for (int i = 0; i < 1024; i++) {
            int cur = freq[i];
            int even_half = (cur + 1) / 2;
            int odd_half = cur / 2;
            // 1 3 5 ...
            if (left & 1) {
                new_freq[i ^ x] += odd_half;
                new_freq[i] += even_half;
            } else {
                new_freq[i ^ x] += even_half;
                new_freq[i] += odd_half;
            }
            left ^= (cur & 1);
        }

        for (int i = 0; i < 1024; i++) {
            freq[i] = new_freq[i];
            new_freq[i] = 0;
        }
    }
    int r = -1, l = -1;
    for (int i = 0; i < 1024; i++) {
        if (freq[i] > 0) {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }
    cout << r << ' ' << l << '\n';
    return 0;
}
