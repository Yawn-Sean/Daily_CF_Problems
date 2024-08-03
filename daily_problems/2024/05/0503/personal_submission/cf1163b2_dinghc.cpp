#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> freq;
    map<int, int> freq_cnt;
    int ans = 0;
    for (int i = 0, c; i < n; i++) {
        cin >> c;
        if (freq.find(c) != freq.end()) {
            if (--freq_cnt[freq[c]] == 0) {
                freq_cnt.erase(freq[c]);
            }
            freq[c]++;
            freq_cnt[freq[c]]++;
        } else {
            freq[c]++;
            freq_cnt[1]++;
        }
        if (freq_cnt.size() == 1) {
            auto& [f, cnt] = *freq_cnt.begin();
            if (f == 1 || cnt == 1) {
                ans = max(ans, i + 1);
            }
        } else if (freq_cnt.size() == 2) {
            auto it = freq_cnt.begin();
            auto& [f1, cnt1] = *it;
            auto& [f2, cnt2] = *++it;
            if (f1 == 1 && cnt1 == 1) {
                ans = max(ans, i + 1);
            } else if (f2 - f1 == 1 && cnt2 == 1) {
                ans = max(ans, i + 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

