#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
    int x = 0; bool f = 0; char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int M = 451;
constexpr int N = 200001;
constexpr int mod = 998244353;

int f[N][M], ans[N];

void add (int &a, int b) {
    a = (a + b >= mod ? a + b - mod : a + b);
}

int main() {
    f[0][0] = f[1][1] = 1;
    rep(i, 2, N - 1) 
        rep(j, 1, min(i, M - 1)) {
            add(f[i][j], f[i - 1][j - 1]);
            add(f[i][j], f[i - j][j]);
        }
    rep(i, 0, N - 1)
        rep(j, 1, M - 1) add(f[i][j], f[i][j - 1]);
    rep(i, 1, N - 1) 
        for (int j = 1; j * j <= i; ++j) 
            if ((i - j * j) % 2 == 0) 
                add(ans[i], f[(i - j * j) / 2][j]);
    per(t, rd(), 1) printf("%d\n", ans[rd()]);
    return 0;
}
