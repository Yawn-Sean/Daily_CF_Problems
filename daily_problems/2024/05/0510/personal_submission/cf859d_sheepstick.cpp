#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1 << 8;

void solve() {
    int n; cin >> n;
    vector<vector<double>> head(1 << n, vector<double>(1 << n, 0)); //head2head
    for (int i = 0; i < 1 << n; i++){
    	for (int j = 0; j < 1 << n; j++){
    		cin >> head[i][j];
    		head[i][j] /= 100.0;
    	}
    }
    vector<vector<double>> winProb(M, vector<double>(M, 0)), acc(M, vector<double>(M, 0));

    auto dfs = [&](auto self, int p, int l, int r) -> void {
    	if (l + 1 == r){
    		winProb[p][l] = 1;
    		acc[p][l] = 0;
    		return;
    	}
    	int mid = (l + r) >> 1;
    	self(self, 2 * p + 1, l, mid);
    	self(self, 2 * p + 2, mid, r);
    	for (int i = l; i < mid; i++){
    		for (int j = mid; j < r; j++){
    			winProb[p][i] += winProb[2 * p + 1][i] * winProb[2 * p + 2][j] * head[i][j];
    		}
    		for (int j = mid; j < r; j++){
    			acc[p][i] = max(acc[p][i], winProb[p][i] * (r - l) / 2 + acc[2 * p + 1][i] + acc[2 * p + 2][j]);
    		}
    	}
    	
    	for (int i = mid; i < r; i++){
    		for (int j = l; j < mid; j++){
    			winProb[p][i] += winProb[2 * p + 2][i] * winProb[2 * p + 1][j] * head[i][j];	
    		}
    		for (int j = l; j < mid; j++){
    			acc[p][i] = max(acc[p][i], winProb[p][i] * (r - l) / 2 + acc[2 * p + 2][i] + acc[2 * p + 1][j]);		
    		}
    		
    	}
    };
    dfs(dfs, 0, 0, 1 << n);
    double res = 0;
    for (auto v : acc[0]){
    	res = max(res, v);
    }
    cout << fixed << setprecision(15) << res << "\n"; 
    

}

int main() {
    
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}