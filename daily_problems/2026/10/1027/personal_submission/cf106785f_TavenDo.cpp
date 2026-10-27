#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())

//

void solve() {
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),b(m+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		cin>>b[i];
	}
	int L=1,R=min(n,m),x=1;
	while(L<=R){
		vector<int>A,B;
		int mid=(L+R)>>1;
		for(int i=1;i<=n;++i){
			if(a[i]<=mid){
				A.push_back(a[i]);
			}
		}
		for(int i=1;i<=m;++i){
			if(b[i]<=mid){
				B.push_back(b[i]);
			}
		}
		if(A==B){
			x=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	cout<<n+m-2*x<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}