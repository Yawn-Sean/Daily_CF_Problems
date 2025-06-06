#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve(){
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    int n = s.size();
    deque<int> d1, d2;
    for (int i = 0; i < n / 2; i++) {
        d1.push_back(s[i]);
        d2.push_back(t[i]);
    }
    if (n % 2 == 1) {
        d1.push_back(s[n / 2]);
    }
    string ans1, ans2;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            if (!d2.empty() && d1.front() >= d2.front()) {
                ans2 += d1.back();
                d1.pop_back();
            } else {
                ans1 += d1.front();
                d1.pop_front();
            }
        } else {
            if (!d2.empty() && d1.front() >= d2.front()) {
                ans2 += d2.back();
                d2.pop_back();
            } else {
                ans1 += d2.front();
                d2.pop_front();
            }
        }
    }
    reverse(ans2.begin(), ans2.end());
    string ans = ans1 + ans2;
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
