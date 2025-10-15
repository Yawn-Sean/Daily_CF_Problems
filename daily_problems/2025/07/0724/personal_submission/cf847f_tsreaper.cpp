#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K, m, W; scanf("%d%d%d%d", &n, &K, &m, &W);

    vector<array<int, 3>> vec(n);
    for (int i = 1; i <= W; i++) {
        int x; scanf("%d", &x);
        vec[x - 1][0]++;
        vec[x - 1][1] = -i;
    }
    for (int i = 0; i < n; i++) vec[i][2] = i;
    sort(vec.begin(), vec.end(), greater<array<int, 3>>());

    auto calc = [&](int idx) {
        vector<array<int, 3>> tmp = vec;
        int pos;
        for (pos = 0; pos < n; pos++) if (tmp[pos][2] == idx) {
            if (m - W > 0) {
                tmp[pos][0] += m - W;
                tmp[pos][1] = -m;
            }
            break;
        }
        sort(tmp.begin(), tmp.end(), greater<array<int, 3>>());
        for (int i = 0; i < n; i++) if (tmp[i][2] == idx) {
            if (i >= K || tmp[i][0] == 0) return 3;
            break;
        }

        if (pos >= K || vec[pos][0] == 0) return 2;
        if (n == K) return 1;
        int need = 0;
        for (int i = pos + 1; i <= K; i++)
            need += vec[pos][0] + 1 - vec[i][0];
        if (need <= m - W) return 2;
        else return 1;
    };

    for (int i = 0; i < n; i++) printf("%d%c", calc(i), "\n "[i + 1 < n]);
    return 0;
}
