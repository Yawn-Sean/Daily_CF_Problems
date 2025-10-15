#include <bits/stdc++.h>
#define MAXN 7000
using namespace std;
typedef pair<int, int> pii;

int n, ans[MAXN][2];
vector<int> A[2];

int deg[MAXN][2];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 2; i++) {
        int K; scanf("%d", &K);
        for (int j = 1; j <= K; j++) {
            int x; scanf("%d", &x);
            A[i].push_back(x);
        }
        for (int j = 0; j < n; j++) deg[j][i] = K;
    }

    queue<pii> q;
    q.push({0, 0}); ans[0][0] = -1;
    q.push({0, 1}); ans[0][1] = -1;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int pos = p.first, who = p.second;
        for (int x : A[who ^ 1]) {
            int nxt = (pos - x + n) % n;
            if (deg[nxt][who ^ 1] > 0) {
                deg[nxt][who ^ 1]--;
                if (ans[pos][who] == -1) {
                    deg[nxt][who ^ 1] = 0;
                    q.push({nxt, who ^ 1});
                    ans[nxt][who ^ 1] = 1;
                } else if (deg[nxt][who ^ 1] == 0) {
                    q.push({nxt, who ^ 1});
                    ans[nxt][who ^ 1] = -1;
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) for (int j = 1; j < n; j++) {
        if (ans[j][i] == -1) printf("Lose");
        else if (ans[j][i] == 1) printf("Win");
        else printf("Loop");
        printf("%c", "\n "[j + 1 < n]);
    }
    return 0;
}
