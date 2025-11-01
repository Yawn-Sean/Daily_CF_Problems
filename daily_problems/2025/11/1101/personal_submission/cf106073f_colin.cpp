#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b);  --i)

constexpr int N = 100007;
constexpr int mod = 1000000007;
constexpr int inv2 = 500000004;

int a[N], ans[N];

int main() {
    int n = rd(), q = rd();
    rep(i, 1, q) a[i] = rd();
    int cont = 0;
    per(i, q, 1) {
        ans[a[i]] = (ans[a[i]] + 1ll * cont * inv2) % mod;
        cont = 1ll * (cont + a[i]) * inv2 % mod;
    }
    ans[1] = (ans[1] + cont) % mod;
    rep(i, 1, n) printf("%d\n", ans[i]);
    return 0;
}