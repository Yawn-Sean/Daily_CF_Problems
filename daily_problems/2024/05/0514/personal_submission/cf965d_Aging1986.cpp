#define TESTS int t; cin >> t; while (t--)
#define TEST 
int main() {
    TEST {
    	int N, K;
    	cin >> N >> K;
    	vi cnt(N - 1, 0);
    	REP(i, N - 1) cin >> cnt[i];
    	ll sum = 0, ans = inf;
    	REP(i, N - 1) {
    		sum += cnt[i];
    		if (i >= K) sum -= cnt[i - K];
    		if (i >= K - 1) chmin(ans, sum);
    	}
    	printf("%lld\n", ans);
    } 
    
    return 0;
}
