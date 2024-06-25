#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
typedef long long ll;
int n, k;
ll a[N], p[20], lg[N];
unordered_map<ll, ll> mp[15];
random_device rd;  // 非确定性随机数生成器
mt19937 rng(rd());  // 高质量随机数生成器
uniform_int_distribution<int> uni(1, 1e9);  // 均匀分布

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int rnd = uni(rng);  // 生成一个随机数作为哈希扰动

    p[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p[i] = p[i - 1] * 10 % k;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll tmp = a[i];
        while (tmp) {
            lg[i]++;
            tmp /= 10;
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= n; j++) {
            ll index = (a[j] % k * p[i] % k) ^ rnd;
            mp[i][index]++;
        }
    }

    ll t, ans = 0;
    for (int i = 1; i <= n; i++) {
        t = ((k - a[i] % k) % k + k) % k;
        ans += mp[lg[i]][t ^ rnd];
        if ((a[i] % k * p[lg[i]] % k + a[i] % k) % k == 0) ans--;
    }
    cout << ans << endl;
}
