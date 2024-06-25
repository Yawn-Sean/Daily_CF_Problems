#define TESTS int t; cin >> t; while (t--)
#define TEST 
int main() {
    TEST {
    	string s; int K;
    	cin >> s >> K;
    	if (K == 0) {
    		printf("1\n");
    		return 0;
    	}
	
    	int mx = 1000, N = s.size();
    	vi dp(mx + 1, 0);
    	REP1(i, 2, mx + 1) dp[i] = dp[__builtin_popcount(i)] + 1;
    	auto solve_combination = [&]() {
    		initFac(N);
    		int pre1 = 0;
    		Mint ret = 0;
    		REP(i, N) {
    			if (s[i] == '1') {
    				REP1(j, pre1, mx + 1) {
    					int left = j - pre1;
    					if (left > N - i - 1) break;
    					if (i == 0 && left == 0) continue;
       					if (i > 0 || left > 1) {
    						if (dp[j] + 1 == K) ret += C(N - i - 1, left);
    					} else {
    						if (K == 1) ret += N - i - 2;
    					}  
    				//	printf("add %d %d %d\n", i, j, ret);
    				}
    				pre1++;
    			}
    		}
    		if (dp[pre1] + 1 == K && N > 1) ret++;
    		return ret;
    	};
    	
    	auto solve_digit_dp = [&]() {
    		vm less(mx + 1, 0);
    		int eq = 0;
    		REP(i, N) {
    			int d = s[i] - '0';
    			vm nless(mx + 1, 0);
    			REP(j, mx + 1) {
    				REP(k, 2) {
    					int nj = j + k;
    					if (nj <= mx) nless[nj] += less[j];
    				}
    			}
    			if (i > 0 && d == 1) {
    				nless[eq]++;
    			}
    			if (i > 0) {
    				nless[1]++;
    			}
    			eq += d;
    			swap(less, nless);
    		}
    		Mint ret = 0;
    		REP1(i, 1, mx + 1) {
    			if (dp[i] + 1 == K) {
    				ret += less[i];
    				if (i == 1) ret--;
    			} 
    		}
    		if (dp[eq] + 1 == K) ret++;
    		return ret;
    	};
    	
    	//Mint ans = solve_combination();
    	Mint ans = solve_digit_dp();
    	printf("%d\n", ans);
    }
    
    return 0;
}
