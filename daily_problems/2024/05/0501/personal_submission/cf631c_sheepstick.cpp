#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }

    vector<array<int,2>> stk;
    for (int i = 0; i < m; i++){
    	int t, r; cin >> t >> r;
    	r--;
    	while(!stk.empty() && stk.back()[0] <= r){
    		stk.pop_back();
    	}	
    	stk.push_back({r, t});
    }

    vector<int> res(n, -1);
    int mx = stk[0][0];
    int L = 0, R = n - 1;
    while(R > mx){
    	res[R] = a[R];
    	R--;
    }

    sort(a.begin(), a.begin() + mx + 1);
    int sz = stk.size();

    for (int w = 0; w < sz; w++){
    	auto [pos, type] = stk[w]; 
    	int st = (w == sz - 1 ? 0 : stk[w + 1][0] + 1);
    	int len = pos - st + 1;

    	if (type == 1){ //nondecreasing
    		//pick maximum for [st, pos];
    		for (int i = R - len + 1, j = st; i <= R; i++, j++){
    			res[j] = a[i];
    		}
    		R -= len;
    	}
    	else {
    		//pick minimum for [st, pos]
    		for (int i = L + len - 1, j = st; i >= L; i--, j++){
    			res[j] = a[i];
    		}
    		L += len;
    	}
    }
    for (auto val : res){
    	cout << val << " ";
    }
    cout << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}