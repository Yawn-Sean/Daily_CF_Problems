#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1'000'000'007;

struct DSU {
    std::vector<int> p;
    int n, sz;
    DSU(int _n) {
    	init(_n);
    }
    
    void init (int _n) {
    	sz = n = _n;
        p.assign(n, -1);
    }

    int find(int x) {
    	int res = x;

    	while (p[res] >= 0)
    		res = p[res];

    	while (p[x] >= 0) {
    		int t = p[x];
    		p[x] = res;
    		x = t;
    	}

    	return res;
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (p[px] > p[py]) std::swap(px, py);
        p[px] += p[py], p[py] = px;
        -- sz;
        return true;
    }

    int size(int x) {
        return -p[find(x)];
    }

    int size() const {
        return sz;
    }
};

struct custom_hash{
	static u64 splitmix64(u64 x) {
		x ^= x << 13;
		x ^= x >> 7;
		x ^= x << 17;
		return x;
	}

	u64 operator()(u64 x) const {
		static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::unordered_map<u64, std::vector<int>, custom_hash> mp;

	std::vector<i64> a(n);

	for (int i = 0; i < n; ++ i) std::cin >> a[i];

	std::vector<std::pair<int, int>> e(m);

	for (int i = 0, u, v; i < m; ++ i) {
		std::cin >> u >> v;
		-- u, -- v;
		mp[a[u] ^ a[v]].push_back(i);
		e[i] = { u, v };
	}

	std::vector<int> pow2(std::max(n, k) + 1);
	pow2[0] = 1;
	for (int i = 1; i < pow2.size(); ++ i)
		pow2[i] = pow2[i - 1] * 2LL % P;

	int ans = (pow2[k] - (i64)mp.size()) % P * pow2[n] % P; 

	DSU dsu(n);

	for (auto &[x, g] : mp) {
		for (int i : g) {
			auto [u, v] = e[i];
			dsu.merge(u, v);
		}

		ans = (1LL * ans + pow2[dsu.size()]) % P;

		for (int i : g) {
			auto [u, v] = e[i];
			dsu.p[u] = -1;
			dsu.p[v] = -1;
		}

		dsu.sz = n;
	}

	std::cout << ans;
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
	while (T --)
		solve();

	return 0;
}