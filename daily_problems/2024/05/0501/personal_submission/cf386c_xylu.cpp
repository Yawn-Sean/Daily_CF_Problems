#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<bool> f(26);
    for (char c : s) f[c - 'a'] = 1;
    int sum = accumulate(f.begin(), f.end(), 0), n = s.size();
    cout << sum << '\n';
    for (int k = 1; k <= sum; k++) {
        long long ans = 0;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        int cc1 = 0, cc2 = 0;
        for (int i = 0, j1 = 0, j2 = 0; i < n; i++) {
            while (j1 < n && cc1 < k) {
                if (cnt1[s[j1] - 'a'] == 0) cc1++;
                cnt1[s[j1] - 'a']++, j1++;
            }
            if (cc1 < k) break;
            while (j2 < n && cc2 <= k) {
                if (cnt2[s[j2] - 'a'] == 0) cc2++;
                cnt2[s[j2] - 'a']++, j2++;
            }
            ans += j2 - j1 + (cc2 == k);
            cnt1[s[i] - 'a']--, cnt2[s[i] - 'a']--;
            if (cnt1[s[i] - 'a'] == 0) cc1--;
            if (cnt2[s[i] - 'a'] == 0) cc2--;
        }
        cout << ans << "\n";
    }

    return 0;
}
