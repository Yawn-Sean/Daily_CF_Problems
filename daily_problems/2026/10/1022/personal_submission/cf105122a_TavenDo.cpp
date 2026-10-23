#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


//

void solve() {
	int k,n;
	cin>>k>>n;
	uniform_int_distribution<int> dist(1, k);
	for(int i=1;i<=n;++i){
		while(1){
			int x=dist(rng),y=dist(rng);
			if(x>y){
				continue;
			}
			cout<<x<<" "<<y<<endl;
			break;
		}
	}

}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}
