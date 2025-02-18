#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    ll k;
    cin >> k;
    vector<ll> pow10(13, 1);
    for (int i = 1; i <= 12; i++) {
        pow10[i] = pow10[i - 1] * 10LL;
    }
    ll rem = k;
    int len = 0;
    for (int digit = 1; digit <= 12; digit++) {
        ll cnt = digit * (pow10[digit] - pow10[digit - 1]);
        len = digit;
        if (rem - cnt <= 0) {
            break;
        }
        rem -= cnt;
    } 
    ll num = pow10[len - 1] - 1 + (rem / len);
    if (rem % len > 0) num++;
    string num_str = to_string(num);
    int i = (rem % len) - 1; 
    if (i == -1) i = len - 1;
    cout << num_str[i] << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
