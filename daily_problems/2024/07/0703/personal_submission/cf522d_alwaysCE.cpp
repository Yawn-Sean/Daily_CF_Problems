#include <bits/stdc++.h>
using i64 = long long;

int inf = 1000000007;

struct Info {
    int dis = inf;
};

Info operator+(Info a, Info b) {
    Info c;
    c.dis = std::min(a.dis, b.dis);
    return c;
}

struct query{
	int l;
	int r;
	int idx;
	query(int _l = 0, int _r = 0, int _idx = 0): l(_l), r(_r), idx(_idx) {}
};

std::map<int,int> last_idx;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<int> arr(n, 0), ans(m, 0);
	std::vector<Info> init(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	
	std::vector<std::vector<query>> q(n);
	SegmentTree<Info> seg(init);
	
	// 按照右端点对查询进行排序,离线处理
	// 靠前的元素距离会包含在后面的区间内
	for (int j = 0; j < m; j++) {
		int l, r;
		std::cin >> l >> r;
		--l; --r;
		q[r].push_back({l, r, j});
	}
	
	for (int i = 0; i < n; i++) {
		int cur = arr[i];
		if (last_idx.count(cur) > 0) {
			int p = last_idx[cur];
			// 更新p下标(可能)的更小距离为i-p
			seg.modify(p, {i - p});
		}
		for (auto& que: q[i]) {
			int idx = que.idx;
			int l = que.l;
			// [l, i+1)区间上进行查询距离最小值
			auto info = seg.rangeQuery(l, i + 1);
			int res = info.dis;
			if (res == inf) {
				// i为query的右端点
				ans[idx] = -1;
			} else {
				ans[idx] = res;
			}
		}
		last_idx[cur] = i;
	}
	
	for (int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
	return 0;
}
