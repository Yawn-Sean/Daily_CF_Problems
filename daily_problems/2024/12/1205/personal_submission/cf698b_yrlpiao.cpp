#include <iostream>
#include <numeric>
using namespace std;
const int N = 1e6 + 10;

int a[N] {}, p[N] {};

int find(int x) {
    if (x != p[x] && p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n; cin >> n;
    iota(p + 1, p + n + 1, 1);
    int r = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i == x) {
            if (r == 0) r = x;
            else {
                ans++;
                p[i] = r;
                a[i] = r;
            }
        }
        else if (find(x) == i) {
            ans++;
            a[i] = r;
            p[i] = r;
        }
        else p[i] = x, a[i] = x;
    }
    if (r == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                r = i;
                break;
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) cout << (a[i] ? a[i] : r) << " ";
    return 0;
}
