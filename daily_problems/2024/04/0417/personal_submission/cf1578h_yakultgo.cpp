#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
string s;
int ord(int l, int r) {
    if (l + 1 == r) return 0;
    int cur = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') cur++;
        if (s[i] == ')') cur--;
        if (cur == 0 && s[i] == '-') return max(ord(l, i - 1) + 1, ord(i + 2, r));
    }
    return ord(l + 1, r - 1);
}
void solve() {
    cin >> s;
    cout << ord(0, s.size() - 1) << endl;
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