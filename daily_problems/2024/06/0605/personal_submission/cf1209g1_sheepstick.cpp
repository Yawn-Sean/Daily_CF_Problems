#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 2E5 + 5;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }
    vector<array<int,2>> cover(M); //cnt, maxR
    for (int i = 0; i < n; i++){
    	cover[a[i]][0]++;
    	cover[a[i]][1] = i;
    }

    int last = 0, R = 0, mxCnt = 0, res = 0;
    for (int i = 0; i < n; i++){
    	if (R < i){
    		res += (i - last) - mxCnt;
    		last = i;
    		mxCnt = 0;
    	}
    	R = max(R, cover[a[i]][1]);
    	mxCnt = max(mxCnt, cover[a[i]][0]);
    }
    res += (n - last) - mxCnt;
    cout << res << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}