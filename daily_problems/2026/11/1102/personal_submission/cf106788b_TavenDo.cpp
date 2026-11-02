#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;
using ULL=unsigned long long;
//std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

//如果一段前缀和另一段前缀相同，说明中间是没变的

const ULL T=1e6+325;
const ULL FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
ULL rng(ULL x) {
    x += 0x9e3779b97f4a7c15 + FIXED_RANDOM;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
void solve() {
	int n,k;
	cin>>n>>k;
	auto wk=[&](int idx,int val)->ULL{
		ULL res=T*idx+val;
		return rng(res);
	};
	vector<ULL>a(n+1);
	vector<int>b(k+1);
	for(int i=1;i<=k;++i){
		a[0]^=wk(i,i);
		b[i]=i;
	}
	int x,y;
	map<ULL,int>adj;
	LL ans=0;
	++adj[a[0]];
	for(int i=1;i<=n;++i){
		cin>>x>>y;
		a[i]=a[i-1];
		a[i]^=wk(x,b[x]);
		a[i]^=wk(y,b[y]);
		swap(b[x],b[y]);
		a[i]^=wk(x,b[x]);
		a[i]^=wk(y,b[y]);
		if(adj.find(a[i])!=adj.end()){
			ans+=adj[a[i]];
		}
		++adj[a[i]];
	}
	cout<<ans<<endl;
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