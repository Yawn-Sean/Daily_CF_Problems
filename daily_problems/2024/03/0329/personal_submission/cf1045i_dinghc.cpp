#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long ans = 0LL;
    map<int, long long> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = 0;
        for (auto& c : s) {
            a ^= 1 << (c - 'a');
        }

        auto it = freq.find(a);
        if (it != freq.end()) {
            ans += it->second++;
        } else {
            freq.insert({a, 1});
        }
        for (int j = 0; j < 26; j++) {
            auto it1 = freq.find(a ^ (1 << j));
            if (it1 != freq.end()) ans += it1->second;
        }
    }

    cout << ans << "\n";

    return 0;
}

