#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

/*
2000 次询问确定一组的解，有 1000 组测试
题目保证 [-1e18, 1e18] 至少包含 5 个完整的段
2e18 + 1 的长度，至少包含 5 个完整段，段长是 len，则 5 * len <= 2e18 + 1
len <= 4e17，这是最大可能的段长
1e18, -1e18, 0 这三个肯定不在同一个段里
我们其实只要关心 [0, 1e18] 的就行了，这里面一定有一个完整段
  
我先挨个走 cnt 步，如果都是一样的，则说明段长至少是 cnt
之后的 2000 - cnt 步我就直接按段跳
或者，询问 0 和 1 一样，说明段长至少是 2，所以下次考虑问 3
如果 3 还一样，说明段长至少是 4，下次问 7 去...
一直倍增问到不一样为止，假设第一个不一样的位置是 pos
则 (0, pos] 之间肯定有段的分界线，我们要找出来
由于按照现在的跳法，一定是相邻段，所以二分答案就可以得到分界点是谁
然后，再跑一遍倍增，找到不一样的颜色后再二分找分界点，这样可以找到本段的右边界
*/

const int N = 2e5 + 10;
const int M = 30 * N; 

int query(LL x) {
    cout << "? " << x << endl;
    string s;
    cin >> s;
    if (s[0] == 'W') {
        return 0;
    }
    return 1;
}

void answer(LL ans) {
    cout << "! " << ans << endl;
}

bool check(LL ans, int color) {
    return query(ans) != color;
}

void solve() {
    int c1 = query(0);
    LL pos = 1;
    LL step = 1;
    const LL MX = 1e18;
    while (true) {
        int c2 = query(pos);
        if (c1 != c2) {
            break;
        }
        step *= 2;
        pos += step;
        pos = min(pos, MX);
    }
    
    LL l = 0, r = pos, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        // 判断 mid 的颜色和 c1 是否一样，true 为不一样
        if (check(mid, c1)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    LL left_bound = -1;
    if (check(l, c1)) {
        left_bound = l;
    } else if (check(r, c1)) {
        left_bound = r;
    } else {
        assert(0 == 1);
    }
    
    pos = left_bound + 1;
    step = 1;
    c1 = query(left_bound);
    while (true) {
        int c2 = query(pos);
        if (c1 != c2) {
            break;
        }
        step *= 2;
        pos += step;
        pos = min(pos, MX);
    }
    
    l = left_bound;
    r = pos;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        // 判断 mid 的颜色和 c1 是否一样，true 为不一样
        if (check(mid, c1)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    
    if (check(l, c1)) {
        answer(l - left_bound);
    } else if (check(r, c1)) {
        answer(r - left_bound);    
    } else {
        assert(0 == 1);
    }
}
