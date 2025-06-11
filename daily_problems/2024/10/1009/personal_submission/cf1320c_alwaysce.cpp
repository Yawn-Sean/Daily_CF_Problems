#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

template<class Info, class Tag>
struct LazySegmentTree {
};

int inf = 1e9;

struct Tag {
    int add = 0;
    
    void apply(Tag t) {
        add += t.add;
    }
};

struct Info {
    int v = -inf;
    
    void apply(Tag t) {
        v += t.add;
    }
};

Info operator+(Info a, Info b) {
    Info c;
    c.v = max(a.v, b.v);
    return c;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, p;
	cin >> n >> m >> p;
	
	vector<int> a(n), b(m);
	vector<int> cost_a(n), cost_b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> cost_a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i] >> cost_b[i];
	}
	
	vector<int> xs(p), ys(p), zs(p);
	for (int i = 0; i < p; i++) {
		cin >> xs[i] >> ys[i] >> zs[i];
	}
	
	vector<int> val = b;
	sort(val.begin(), val.end());
	int k = unique(val.begin(), val.end()) - val.begin();
	
	map<int,int> mp;
	for (int i = 0; i < k; i++) {
		mp[val[i]] = i; // b[i]出现的数值 排序后的idx
	}
	
	vector<Info> init(k);
	for (int i = 0; i < m; i++) {
		init[mp[b[i]]].v = max(init[mp[b[i]]].v, -cost_b[i]);
	}
	
	LazySegmentTree<Info, Tag> seg(init);
	
	vector<int> order1(n), order2(p);
	iota(order1.begin(), order1.end(), 0);
	sort(order1.begin(), order1.end(), [&](int i, int j) {
		return a[i] < a[j];	
	});
	
	iota(order2.begin(), order2.end(), 0);
	sort(order2.begin(), order2.end(), [&](int i, int j) {
		return xs[i] < xs[j];
	});
	
	int idx = 0, ans = -inf * 2;
	// 按照atk排序
	for (auto& i: order1) {
		// atk值大于怪物atk 的所有怪物
		while (idx < p and a[i] > xs[order2[idx]]) {
			int l = 0, r = k - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (val[mid] > ys[order2[idx]]) {
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			// 找到def值 > ys[order2]
			Tag tmp;
			tmp.add = zs[order2[idx]];
			// 对于>=def这一部分的所有区间 加上zs(之前扣掉了)
			seg.rangeApply(1, 0, k, l, k, tmp);
			idx++;
		}
		int tmp_v = seg.rangeQuery(0, k).v; // 选择atk[i]区间上的最大值
		// cout << a[i] << ' ' << tmp_v << '\n';
		ans = max(ans, tmp_v - cost_a[i]);
	}
	cout << ans << '\n';
	return 0;
}
