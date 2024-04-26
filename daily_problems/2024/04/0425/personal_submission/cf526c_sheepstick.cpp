#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 c, hr, hb, wr, wb; cin >> c >> hr >> hb >> wr >> wb;

    i64 res = 0;
    // if any weight > sqrt(c)， enumerate
    // else, their weight product <= c, then there exists one color with optimal count < sqrt(c)
    for (i64 i = 0; i * i <= c; i++){
    	if (i * wr <= c){
    		res = max(res, i * hr + (c - i * wr) / wb * hb);
    	}
    	if (i * wb <= c){
    		res = max(res, i * hb + (c - i * wb) / wr * hr);
    	}
    }
    cout << res << "\n";

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