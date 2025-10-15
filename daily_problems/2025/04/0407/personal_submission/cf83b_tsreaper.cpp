#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long K;
map<int, vector<int>> mp;

bool vis[MAXN + 5];

int main() {
    scanf("%d%lld", &n, &K);
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        mp[A[i]].push_back(i);
        sm += A[i];
    }
    if (K > sm) { printf("-1\n"); return 0; }

    int cnt = n, last = 0;
    for (auto &p : mp) {
        long long t = 1LL * (p.first - last) * cnt;
        if (K >= t) {
            K -= t;
            cnt -= p.second.size();
            last = p.first;
            for (int x : p.second) vis[x] = true;
        } else {
            bool flag = (K >= t - cnt);
            K %= cnt;
            vector<int> front, back;
            for (int i = 1; i <= n; i++) if (!vis[i]) {
                if (K > 0) {
                    K--;
                    if (flag && A[i] == p.first) continue;
                    back.push_back(i);
                } else {
                    front.push_back(i);
                }
            }
            for (int x : front) printf("%d ", x);
            for (int x : back) printf("%d ", x);
            printf("\n");
            break;
        }
    }

    return 0;
}
