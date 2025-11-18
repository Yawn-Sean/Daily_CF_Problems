#include <bits/stdc++.h>

#define x first
#define y second
#define ls (k << 1)
#define rs ((k << 1) | 1)

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
const int M = 1e4 + 10;
const int INF = 1e9 + 10;

/*
对于 i 位置的查询
我们其实关心的是，对于左端点 <= i 且右端点 >= i 的操作 [l, r]
其中没有出现的最大的 <= i 的 l 是谁
现在需要同时考虑两个端点，有点麻烦
让求的这个东西有单调性，可以二分
所以我们考虑二分那个没出现的 l，为 ans
然后考虑 [ans, i] 是否都出现过了
这个如何搞呢？
现在麻烦的点在于我们想让 r 也满足题意
那么不妨对于每个 l，只保留最大的 r
那么只要看 [ans, i] 中，r 是否都 >= i 就好了
即 [ans, i] 的 r 的最小值
使用线段树维护单点赋值和区间 min 就好了
*/

SegmentTree smt;
int n, q;

void solve() {   
    cin >> n >> q;
    smt.init(n);
    
    auto check = [&] (int ans, int pos) -> bool {
        int r = pos;
        int l = r - ans + 1;
        return smt.query(1, n, l, r, 1) >= pos;
    };
    
    while (q--) {
        int op, l, r, pos;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            smt.modify(1, n, l, r, 1);
        } else {
            cin >> pos;
            int l = 1, r = pos, mid;
            while (l + 1 < r) {
                mid = (l + r) / 2;
                if (check(mid, pos)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (check(r, pos)) {
                cout << r + 1 << "\n";    
            } else if (check(l, pos)) {
                cout << l + 1 << "\n";
            } else {
                cout << 1 << "\n";
            }
        }
    }
}
