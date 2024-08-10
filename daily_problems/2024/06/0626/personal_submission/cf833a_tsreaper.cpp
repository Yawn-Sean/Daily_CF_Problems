#include <bits/stdc++.h>
#define MAGIC 1000
using namespace std;
typedef pair<int, int> pii;

bool flag[MAGIC + 10];
vector<int> prime;

vector<int> gao(int x) {
    vector<int> ret;
    for (int p : prime) {
        if (p > x) break;
        if (x % p) continue;
        for (; x % p == 0; x /= p);
        ret.push_back(p);
    }
    if (x > 1) ret.push_back(x);
    return ret;
}

bool solve() {
    int X, Y; scanf("%d%d", &X, &Y);
    int t = pow(1LL * X * Y, 1.0 / 3) + 1e-9;
    if (1LL * t * t * t != 1LL * X * Y) return false;

    vector<int> vec = gao(t);
    for (int p : vec) if (X % p || Y % p) return false;

    for (int p : vec) {
        int cx = 0, cy = 0;
        for (; X % p == 0; X /= p) cx++;
        for (; Y % p == 0; Y /= p) cy++;
        int tot = cx + cy;
        if (tot % 3) return false;
        tot /= 3;

        int y = 2 * cy - cx;
        if (y < 0 || y % 3) return false;
        y /= 3;

        int x = cx - y;
        if (x < 0 || x % 2) return false;
        x /= 2;

        if (x + y != tot) return false;
    }
    return true;
}

int main() {
    for (int i = 2; i <= MAGIC; i++) if (!flag[i]) {
        prime.push_back(i);
        for (int j = i * 2; j <= MAGIC; j += i) flag[j] = true;
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        if (solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
