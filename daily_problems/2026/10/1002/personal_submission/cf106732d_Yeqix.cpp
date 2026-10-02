#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = std::ranges;

constexpr int md = 998244353;

void ad(int& a, int b) {
    a += b;
    if (a >= md) {
        a -= md;
    }
}

template <class T>
struct BIT {
    int n;
    vector<T> w;
    BIT(int n) {
        w.resize(n + 1);
        this->n = n;
    }

    void add(int x, T v) {
        while (x <= n) {
            ad(w[x], v);
            x += x & -x;
        }
    }

    T ask(int x) {
        T ans = 0;
        while (x) {
            ad(ans, w[x]);
            x -= x & -x;
        }
        return ans;
    }

    T ask(int l, int r) {
        if (l > r) {
            return 0;
        }
        int ans = ask(r);
        ad(ans, md - ask(l - 1));
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1);
    BIT<int> bt(n + 10);
    bt.add(1, 1);
    int l = 1, r = 1, mex0 = 0, mex1 = 0;
    vector<int> stl(R + 1), str(L);
    for (int i = 1; i <= n; i++) {
        if (a[i] <= R) {
            stl[a[i]]++;
            if (stl[a[i]] == 1) {
                mex0++;
            }
        }
        if (a[i] < L) {
            str[a[i]]++;
            if (str[a[i]] == 1) {
                mex1++;
            }
        }

        while (l <= i && mex0 == R + 1) {
            if (a[l] <= R) {
                stl[a[l]]--;
                mex0 -= (stl[a[l]] == 0);
            }
            l++;
        }
        while (r <= i && mex1 == L) {
            if (a[r] < L) {
                str[a[r]]--;
                mex1 -= (str[a[r]] == 0);
            }
            r++;
        }

        if (l <= i) {
            dp[i] = bt.ask(l, r - 1);
        }
        bt.add(i + 1, dp[i]);
    }

    cout << dp[n];
    return 0;
}