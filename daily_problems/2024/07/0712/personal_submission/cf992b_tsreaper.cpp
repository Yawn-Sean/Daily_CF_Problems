#include <bits/stdc++.h>
#define MAGIC ((int) 4e4)
using namespace std;
typedef pair<int, int> pii;

bool flag[MAGIC + 10];
vector<int> prime;

unordered_map<int, int> gao(int x) {
    unordered_map<int, int> mp;
    for (int p : prime) {
        if (p > x) break;
        if (x % p) continue;
        int t = 1;
        while (x % p == 0) x /= p, t *= p;
        mp[p] = t;
    }
    if (x > 1) mp[x] = x;
    return mp;
}

int main() {
    int L, R, X, Y; scanf("%d%d%d%d", &L, &R, &X, &Y);
    if (Y % X) { printf("0\n"); return 0; }

    for (int i = 2; i <= MAGIC; i++) if (!flag[i]) {
        prime.push_back(i);
        for (int j = i * 2; j <= MAGIC; j += i) flag[j] = true;
    }

    auto mpX = gao(X), mpY = gao(Y);
    vector<pii> vec;
    int m = mpY.size();
    for (int i = 0; i < (1 << m); i++) {
        int u = 1, v = 1;
        int j = 0;
        for (auto &p : mpY) {
            if (i >> j & 1) u *= max(1, mpX[p.first]), v *= p.second;
            else u *= p.second, v *= max(1, mpX[p.first]);
            j++;
        }
        if (u >= L && u <= R && v >= L && v <= R) vec.push_back({u, v});
    }

    sort(vec.begin(), vec.end());
    printf("%d\n", unique(vec.begin(), vec.end()) - vec.begin());
    return 0;
}
