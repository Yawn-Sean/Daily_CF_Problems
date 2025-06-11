#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 1e9+7;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	/*
		给你一棵树 修改第一条边的边权c
		这条边的边权c要能够满足它依然会在MST中
		
		改大 或者 改小 都可以
		求这个最大值
		
		二分边权然后Kruskal? log(1e9)=30
		
		忽略第一条边 把u1,v1看成一个节点
		Consider the vertices in the edge 1 as one first
	
		等价于去掉第一条边之后 会变成两个连通块
	*/

	vector<int> us(m), vs(m), ws(m);
	for (int i = 0; i < m; i++) {
		cin >> us[i] >> vs[i] >> ws[i];
	}
	
	vector<int> order(m-1);
	iota(order.begin(), order.end(), 1);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return ws[i] < ws[j];
	});
	
	// d1包含了第一条边
	DSU d1(n + 1), d2(n + 1);
	d1.merge(us[0], vs[0]);
	
	for (auto&i: order) {
		if (!d1.same(us[i], vs[i])) {
			d1.merge(us[i], vs[i]);
			d2.merge(us[i], vs[i]); 
		}
	}
	
	for (auto&i: order) {
		// 说明去掉第一条边之后 第一个断掉的权重最小是多少 那么至多只能增加到这里
		if (!d2.same(us[i], vs[i])) {
			cout << ws[i]; // 增加到这么多
			return 0;
		}
	}
	
	cout<< 1000000000;
	return 0;
}
