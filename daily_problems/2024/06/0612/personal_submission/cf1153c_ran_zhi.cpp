#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void solve() { 
    int n; cin >> n;
    string s; cin >> s;
    if (s.size() % 2) return (void)(cout << ":(" << endl);
    int cnt = 0;
    for (auto &x : s) {
        if (x == '(') cnt += 1;
    }
    int l = n / 2 - cnt, cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (x == '(') cur ++;
        else if (x == ')') cur --;
        else {
            if (l) l--, cur++, s[i] = '(';
            else cur--, s[i] = ')';
        }
        if (cur <= 0 && i != s.size() - 1) return (void)(cout << ":(" << endl); 
    }
    if (cur == 0) cout << s << endl;
    else cout << ":(" << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
