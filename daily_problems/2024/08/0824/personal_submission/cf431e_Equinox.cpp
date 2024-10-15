#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    
    SegmentTree(int _n): n(_n), info(2 << (32 - __builtin_clz(_n))) {}

    template<class T>
    SegmentTree(std::vector<T>& _init): SegmentTree(_init.size()) {
        auto build = [&](auto&& self, int p, int l, int r) {
            if (l == r) {
                info[p] = _init[l];
                return;
            }
            int mid = l + r >> 1;
            self(self, p << 1, l, mid), self(self, p << 1 | 1, mid + 1, r);
            pull(p);
        };
        build(build, 1, 0, n - 1);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (l == r) {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) modify(p << 1, l, mid, x, v);
        else modify(p << 1 | 1, mid + 1, r, x, v);
        pull(p);
    }

    void modify(int x, const Info& v) {
        modify(1, 0, n - 1, x, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) return Info();
        if (x <= l && r <= y) {
            return info[p];
        }
        int mid = l + r >> 1;
        return rangeQuery(p << 1, l, mid, x, y) + rangeQuery(p << 1 | 1, mid + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }
};

struct Info{
	i64 s = 0;
	int val = 0, sz = 0;

	friend Info operator+ (const Info &a, const Info &b) {
		if (!a.sz) return b;
		if (!b.sz) return a;
		return {
			a.s + b.s + 1LL * (b.val - a.val) * a.sz,
			b.val,
			a.sz + b.sz
		};
	}
};

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> h(n), val;

	for (int i = 0; i < n; ++ i)
		std::cin >> h[i], val.push_back(h[i]);

	std::vector<std::array<i64, 2>> o(q);

	for (int i = 0, op; i < q; ++ i) {
		std::cin >> op;
		if (op == 1) {
			std::cin >> o[i][0] >> o[i][1];
			-- o[i][0];
			val.push_back(o[i][1]);
		}
		else {
			o[i][0] = -1;
			std::cin >> o[i][1];
		}
	}

	std::ranges::sort(val);

	val.erase(std::unique(val.begin(), val.end()), val.end());

	std::map<i64, int> mp;
	std::vector<Info> info(val.size());

	for (int i = 0; i < val.size(); ++ i)
		mp[val[i]] = i, info[i].val = val[i];

	for (int x : h)
		++ info[mp[x]].sz;

	SegmentTree<Info> sgt(info);

	for (auto &[p, v] : o) {
		if (~p) {
			int i = mp[h[p]];
			-- info[i].sz;
			sgt.modify(i, info[i]);

			i = mp[h[p] = v];
			++ info[i].sz;
			sgt.modify(i, info[i]);
		}
		else {
			int lo = -1, hi = val.size();

			while (lo + 1 < hi) {
				int x = lo + hi >> 1;
				if (sgt.rangeQuery(0, x).s <= v)
					lo = x;
				else
					hi = x;
			}

			auto t = sgt.rangeQuery(0, lo);

			std::cout << std::fixed << std::setprecision(10) << 1.0 * (v - t.s) / t.sz + t.val << '\n';
		}
	}


}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main () {
	#ifdef DEBUG
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int T = 1;
	// std::cin >> T;
	while (T --) {
		solve();
	}

	return 0;
}