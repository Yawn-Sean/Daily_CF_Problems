#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, K, A[MAXN + 5];

vector<int> e[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > 0) e[A[i]].push_back(i);
    }

    vector<int> vec;
    int base = 0;
    for (int i = 1; i <= n; i++) if (A[i] == 0) {
        int cnt = 0, now = i;
        while (true) {
            cnt++;
            if (now == K) { base = cnt; break; }
            if (e[now].empty()) { vec.push_back(cnt); break; }
            now = e[now][0];
        }
    }

    bitset<1001> bs;
    bs[0] = true;
    for (int x : vec) bs |= bs << x;
    for (int i = 0; i < bs.size(); i++) if (bs[i]) printf("%d\n", i + base);
    return 0;
}
