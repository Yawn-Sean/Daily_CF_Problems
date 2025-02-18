#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1E9 + 7;

template <class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int _n) : n(_n), info(2 << (32 - __builtin_clz(n))), tag(2 << (32 - __builtin_clz(n))){}
    
    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag &t) {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    template<class T>
    LazySegmentTree(std::vector<T>& _init): LazySegmentTree(_init.size()) {
        auto build = [&](auto&& self, int p, int l, int r) {
            if (l == r) {
                info[p] = { _init[l] };
                return;
            }
            int mid = l + r >> 1;
            self(self, p << 1, l, mid), self(self, p << 1 | 1, mid + 1, r);
            pull(p);
        };
        build(build, 1, 0, n - 1);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) return Info();
        if (x <= l && r <= y) 
            return info[p];
        push(p);
        int mid = l + r >> 1;
        return rangeQuery(p << 1, l, mid, x, y) + rangeQuery(p << 1 | 1, mid + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v){
        if (l > y || r < x) return;
        if (x <= l && r <= y) { 
            apply(p, v);
            return;
        }

        int mid = l + r >> 1;
        push(p);
        rangeApply(p << 1, l, mid, x, y, v);
        rangeApply(p << 1 | 1, mid + 1, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) {
        rangeApply(1, 0, n - 1, l, r, v);
    }
};

struct Tag {
    i64 add = 0;

    void apply(const Tag& t) {
        add += t.add;
    }
};

struct Info {
    i64 mi = inf64;
    void apply(const Tag &t) {
        mi += t.add;
    }
};

Info operator + (const Info &x, const Info &y) {
    return { std::min(x.mi, y.mi) };
}

struct Edge{
	int v, w;
};

void solve(){
	int n, q;
	std::cin >> n >> q;

	std::vector<Edge> e;
	std::vector<std::vector<int>> g(n);
	std::vector<i64> up(n);

	for (int i = 0, u, v, w, ed = 2 * n - 2; i < ed; ++ i) {
		std::cin >> u >> v >> w;
		-- u, -- v;
		if (v) {
			e.emplace_back(v, w);
			g[u].push_back(i);
		}
		else {
			e.emplace_back(u, w);
			up[u] = w;
		}
	}


	std::vector<int> dfn(n), sz(n);
	std::vector<i64> d(n);
	int cur = 0;
	
	auto dfs = [&](auto &&self, int u) -> void {
		dfn[u] = cur ++, sz[u] = 1;
		for (int i : g[u]) {
			auto [v, w] = e[i];
			d[v] = d[u] + w;
			self(self, v);
			sz[u] += sz[v];
		}
	};

	dfs(dfs, 0);

	std::vector<i64> val(n, -1);
	for (int i = 0; i < n; ++ i) {
		assert(val[dfn[i]] == -1);
		val[dfn[i]] = up[i] + d[i];
	}

	LazySegmentTree<Info, Tag> sgt(val);

	auto get = [&](int u) -> i64 {
		return sgt.rangeQuery(dfn[u], dfn[u]).mi;
	};

	for (int i = 0, op, x, y; i < q; ++ i) {
		std::cin >> op >> x >> y;
		if (op == 1) {
			if (x >= n) {
				int v = e[x - 1].v;
				sgt.rangeApply(dfn[v], dfn[v], Tag{y - up[v]});
				up[v] = y;
			}
			else {
				int v = e[x - 1].v;
				sgt.rangeApply(dfn[v], dfn[v] + sz[v] - 1, Tag{y - e[x - 1].w});
				e[x - 1].w = y;
			}
		}
		else {
			-- x, -- y;
			if (dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + sz[x] - 1) {
				std::cout << get(y) - up[y] - get(x) + up[x] << '\n';
				continue;
			}
			std::cout << sgt.rangeQuery(dfn[x], dfn[x] + sz[x] - 1).mi + get(y) - up[y] - get(x) + up[x] << '\n';
		}
	}
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main() {
	#ifdef DEBUG
		freopen("in.txt", 'r', stdin);
		freopen("out.txt", 'w', stdout);
	#endif
	int t = 1;
	// std::cin >> t;
	while(t --)
		solve();
	return 0;
}