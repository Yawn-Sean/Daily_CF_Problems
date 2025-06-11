#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 N = 100005, INF = 1e9;
i64 w[N];

// 动态开点线段树板子
struct Node{
    i64 l, r;
    i64 sum, cnt;
}tr[N * 50];

i64 root = 0, idx = 0;

void pushup(i64 u) {
    tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
    tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
}

// tube[x] 目前体积/数量
// cnt = (V<=mid)的数量
// sum + K >= cnt * mid, 说明增加K 最大值为mid是一个可行的方式
void modify(i64& u, i64 l, i64 r, i64 x, i64 v, i64 vc) {
    if (!u) {
    	u = ++idx;
    }
    
    if (l == r) {
        tr[u].sum += v;
        tr[u].cnt += vc;
        return;
    }
    
    i64 mid = (l + r) / 2;
    if (x <= mid) { 
    	modify(tr[u].l, l, mid, x, v, vc);
    } else {
    	modify(tr[u].r, mid + 1, r, x, v, vc);
    }
    pushup(u);
}

i64 query(i64 u, i64 L, i64 R, i64 l, i64 r, bool f) {
    // f = 1表示查询总体积, f = 0表示查询个数
    if (!u) {
    	return 0;
    }
    
    if (R == INF && r > R) {
    	r = INF;
    }
    
    if (l <= L && R <= r) {
        if (f) {
        	return tr[u].sum;
        }
        return tr[u].cnt;
    }
    
    i64 mid = (L + R) / 2;
    i64 res = 0;
    
    if (l <= mid) {
    	res = query(tr[u].l, L, mid, l, r, f);
    }
    
    if (mid < r) {
    	res += query(tr[u].r, mid + 1, R, l, r, f); 
    }
	return res;
}

// 对于mid的二分
long double solve(i64 x) {
    long double l = 0, r = 1e15;
    while(r - l > 1e-5) {
        long double mid = (l + r) / 2;
        long double count = 1.0 * query(root, 0, INF, 0, mid, 0);
        long double volume = 1.0 * query(root, 0, INF, 0, mid, 1);
        if (count * mid >= volume + x) {
        	r = mid;
        } else {
        	l = mid;
        }
    }
    return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		// 线段树存权值 x=w[i], v=w[i], vcnt=1
		modify(root, 0, INF, w[i], w[i], 1);
	}
    
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
        	i64 x, y;
            cin >> x >> y;
            // 线段树内的1权重更新
            modify(root, 0, INF, w[x], -w[x], -1);
            modify(root, 0, INF, y, y, 1);
            w[x] = y;
        } else {
            i64 x;
            cin >> x;
            cout << fixed << setprecision(10) << solve(x) << '\n';
        }
    }

    return 0;
}
