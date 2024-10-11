#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <numeric>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
int n, ans[20], cnt = 0;
int out(int x,int y,int fx,int fy) {
    if (x > fx || y > fy) return 0;
    printf("? %d %d %d %d\n", x, y, fx, fy);
    fflush(stdout);
    int num;
    scanf("%d", &num);
    return num;
}

void solve(int x, int y, int fx, int fy) {
    int l = x, r = fx, res = x;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int f = out(mid, y, fx, fy);
        if (f == 0) r = mid - 1;
        else l = mid + 1, res = mid;
    }
    ans[++cnt] = res;
    l = y, r = fy, res = y;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int f = out(x,mid, fx, fy);
        if (f == 0) r = mid - 1;
        else l = mid + 1, res = mid;
    }
    ans[++cnt] = res;
    l = x, r = fx, res = fx;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int f = out(x, y,mid, fy);
        if (f == 0) l = mid + 1;
        else r = mid - 1, res = mid;
    }
    ans[++cnt] = res;
    l = y, r = fy, res = fy;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int f = out(x, y, fx, mid);
        if (f == 0) l = mid + 1;
        else r = mid - 1, res = mid;
    }
    ans[++cnt] = res;
}

int main() {
    scanf("%d", &n);
    int l = 1, r = n, flag = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int f = out(1, 1, n, mid);
        int g = out(1, mid + 1, n, n);
        if (f && g) flag = 1;
        if (f == 0) l = mid + 1;
        else r = mid - 1;
    }
    if(flag) {
        solve(1, 1, n, l);
        solve(1, l + 1, n, n);
    } else {
        l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int f = out(1, 1, mid, n);
            if (f == 0) l = mid + 1;
            else r = mid - 1;
        }
        solve(1, 1, l, n);
        solve(l + 1, 1, n, n);
    }
    printf("! ");
    for(int i = 1; i <= 8; i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
