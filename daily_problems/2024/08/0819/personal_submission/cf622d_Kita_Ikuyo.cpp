#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define int long long
#define ull unsigned long long
#define lowbit(i) ((i)&(-i))
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define per(i, a, b) for(int i=a;i>=b;i--)

typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int inf = 4e18;
const int N = 2e5 + 200;

int qpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int a[1000500];

signed main() {
    IOS
    int n;
    cin >> n;
    int j = 1;
    for (int i = 1; i <= n; i += 2) {
        a[j] = a[n - j + 1] = i;
        j++;
    }
    j = 1;
    for (int i = 2; i <= n; i += 2) {
        a[n + 1 + j] = a[2 * n - (j - 1)] = i;
        j++;
    }
    a[n + 1] = n;
    for (int i = 1; i <= 2 * n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
