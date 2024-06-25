#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<char> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }
    int m = st.size();
    cout << m << endl;
    for (int len = 1; len <= m; len++) {
        ll cur = 0;
        vector<int> cnt1(26), cnt2(26);
        int r1 = 0, r2 = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            while (r1 < n && s1 < len) {
                if (++cnt1[s[r1] - 'a'] == 1)
                    s1++;
                r1++;
            }
            if (s1 < len) break;
            while (r2 < n && s2 <= len) {
                if (++cnt2[s[r2] - 'a'] == 1)
                    s2++;
                r2++;
            }
            cur += r2 - r1;
            if (s2 == len)
                cur += 1;
            if (--cnt1[s[i] - 'a'] == 0) s1--;
            if (--cnt2[s[i] - 'a'] == 0) s2--;
        }
        cout << cur << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}