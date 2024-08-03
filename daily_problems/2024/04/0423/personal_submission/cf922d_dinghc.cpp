#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    auto f = [&] (string& t) -> pair<int, int> {
        int res = 0, s = 0;
        for (auto& c : t) {
            if (c == 's') {
                s++;
            } else {
                res += s;
            }
        }
        return {res, s};
    };

    long long ans = 0LL;
    vector<pair<int, int>> freq(n);
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        auto [cnt, s] = f(t);
        freq[i] = {s, t.length() - s};
        ans += cnt;
    }

    ranges::sort(freq, [&] (pair<int, int>& a, pair<int, int>& b) {
        auto&[s_a, h_a] = a;
        auto&[s_b, h_b] = b;
        return 1LL * s_a * h_b > 1LL * h_a * s_b;
    });

    int sum = 0;
    for (int i = 0; i < n; i++) {
        auto&[s, h] = freq[i];
        ans += 1LL * h * sum;
        sum += s;
    }

    cout << ans << "\n";

    return 0;
}

