#include <bits/stdc++.h>

using namespace std;

constexpr int A = 1e7;
vector<int> lpf(A + 1);
vector<int> pr;

auto init = [] {
    for (int i = 2; i <= A; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= A; ++j) {
            lpf[i * pr[j]] = pr[j];
            if (pr[j] == lpf[i]) break;
        }
    }
    return 0;
}();

constexpr int N = 1e5;
int n;
int a[N];

bool solve() {
    set<int> s;
    auto check = [&] (int x) -> bool {
        while (x > 1) {
            int p = lpf[x];
            if (s.count(p) > 0) return false;
            s.insert(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        return true;
    };
    int g = gcd(a[0], a[1]);
    if (!check(a[0] / g) || !check(a[1] / g)) return false;
    for (int i = 2; i < n; i++) {
        if (a[i] % g != 0) return false;
        if (!check(a[i] / g)) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}

