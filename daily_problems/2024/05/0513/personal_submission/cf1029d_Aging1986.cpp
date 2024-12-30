#define TESTS int t; cin >> t; while (t--)
#define TEST 
int main() {
    TEST {
    	int N, K;
    	cin >> N >> K;
    	vi v(N);
    	REP(i, N) cin >> v[i];
		int seed = rng() % 1000000000;
    	unordered_map<int, int> up[11], down[11];
    	auto get = [&](unordered_map<int, int> &m, int key) {
    		auto it = m.find(key ^ seed);
    		if (it != m.end()) return it->second; else return 0;
    	};
    	auto upd = [&](unordered_map<int, int> &m, int key) {
    		m[key ^ seed]++;
    	};
    	ll ans = 0;
    	REP(i, N) {
    		int d = 0, e = v[i] % K, f = e;
    		while (v[i] > 0) v[i] /= 10, d++;
    		if (!up[d].empty()) ans += get(up[d], e == 0 ? 0 : K - e);
    		REP1(j, 1, 11) {
    			e = 1ll * e * 10 % K;
				if (!down[j].empty()) ans += get(down[j], e == 0 ? 0 : K - e);
				upd(up[j], e);
    		}
    		upd(down[d], f);
    	}
    	printf("%lld\n", ans);
    }
    
    return 0;
}
