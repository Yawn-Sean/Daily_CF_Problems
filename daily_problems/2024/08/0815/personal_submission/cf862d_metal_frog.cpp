#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 1005;
char buf[N];
int n;

int getRes() {
    int dis;
    scanf("%d", &dis);
    return dis;
}

void flushBuffer() {
    buf[n] = '\0';
    printf("? %s\n", buf);
    fflush(stdout);
}

void solve() {
    n = getRes();
    for (int i = 0; i < n; i++) buf[i] = '0';
    flushBuffer();
    int delta = getRes();
    buf[0] = '1';
    for (int i = 1; i < n; i++) buf[i] = '0';
    flushBuffer();
    int delta1 = getRes();
    int pos0 = -1, pos1 = -1;
    bool rev = false;
    if (delta == delta1 + 1) {
        pos1 = 0;
        rev = true;
    } else {
        pos0 = 0;
    }

    if (rev) delta = n - delta;
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        for (int i = 0; i <= mid; i++) {
            buf[i] = rev ? '1' : '0';
        }
        int cnt = 0;
        for (int i = mid + 1; i < n; i++) {
            buf[i] = rev ? '0' : '1';
            cnt++;
        }
        flushBuffer();
        int res = getRes();
        if (res == delta + cnt) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (rev) {
        pos0 = lo;
    } else {
        pos1 = lo;
    }
    
    printf("! %d %d\n", pos0 + 1, pos1 + 1);
    fflush(stdout);
}
 
int main() {
    solve();
}
