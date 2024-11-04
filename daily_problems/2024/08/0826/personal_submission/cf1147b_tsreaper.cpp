#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
vector<int> vec[MAXN];

bool check(int K) {
    for (int i = 0; i < n; i++) if (vec[i] != vec[(i + K) % n]) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        vec[x].push_back((y - x + n) % n); vec[y].push_back((x - y + n) % n);
    }
    for (int i = 0; i < n; i++) sort(vec[i].begin(), vec[i].end());
    for (int i = 1; i < n; i++) if (n % i == 0 && check(i)) { printf("Yes\n"); return 0; }
    printf("No\n"); return 0;
}
