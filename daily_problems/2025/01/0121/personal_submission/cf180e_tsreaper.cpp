#include <bits/stdc++.h>
#define MAXM ((int) 1e5)
using namespace std;

int n, m, K;

vector<int> pos[MAXM + 5];

bool check(int lim) {
    for (int i = 1; i <= m; i++) if (pos[i].size() >= lim)
        for (int j = 0; j + lim <= pos[i].size(); j++) {
            int len = pos[i][j + lim - 1] - pos[i][j] + 1;
            if (len - lim <= K) return true;
        }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        pos[x].push_back(i);
    }
    
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(mid)) head = mid;
        else tail = mid - 1;
    }
    printf("%d\n", head);
    return 0;
}
