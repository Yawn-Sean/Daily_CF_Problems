#define TESTS int t; cin >> t; while (t--)
#define TEST 
int main() {
    TEST {
    	int N, C, D;
    	cin >> N >> C >> D;
    	vpii c, d;
    	int mxc = 0, mxd = 0;
    	REP(i, N) {
    		int b, p; char type;
    		cin >> b >> p >> type;
    		if (type == 'C') {
    			if (p <= C) {
    				chmax(mxc, b);
    				c.pb({p, b});
    			}
    		} else {
    			if (p <= D) {
    				chmax(mxd, b);
    				d.pb({p, b});
    			}
    		}
    	}
    	sort(all(c)); 
    	sort(all(d)); 
    	
    	int ans = mxc > 0 && mxd > 0 ? mxc + mxd : 0;
    	
    	auto solve = [&](vpii &p, int tar) {
    		if (p.size() < 2) return;
    		for (int i = p.size() - 1, j = 0, mx = 0, mx2 = 0; i >= 0; i--) {
    			while (j < p.size() && p[j].first + p[i].first <= tar) {
    				if (p[j].second > mx) mx2 = mx, mx = p[j].second;
    				else if (p[j].second > mx2) mx2 = p[j].second;
    				++j;
    			}
    			int sec = mx == p[i].second ? mx2 : mx;
    			if (sec > 0) chmax(ans, p[i].second + sec);
    		}	
    	};
    	solve(c, C);
    	solve(d, D);
    	printf("%d\n", ans);
    }
    
    return 0;
}
