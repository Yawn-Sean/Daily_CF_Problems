/**
https://codeforces.com/contest/1672/submission/268771084
1672D
2024/7/4 Y1
1700
array, Counter
TLE for pypy3 -> convert to C++
 */

#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[200001], b[200001],
ca[200001], cb[200001];

void init() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
}

bool solve() {
    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));
    for (int i = 0; i < n; ++i)
        ++ca[a[i]];
    int x0 = -1, i = 0, j = 0;
    while (i < n || j < n) {
        //printf("n i j a[i] b[j]= %d %d %d %d %d\n", n, i, j, a[i], b[j]);
        int x = i < n ? a[i] : -1,
            y = b[j];
        if (x != y) {
            if (y == x0 && cb[y] > 0) {
                --cb[y];
                ++j; 
            }
            else if (ca[x] > 1) {
                --ca[x];
                ++cb[x]; 
                ++i;
            }   
            else
                return false;
        } else {
            --ca[x];
            ++i;
            ++j; 
            x0 = x;
        }
    }
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        init();
        bool ans = solve();
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
