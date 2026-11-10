#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl "\n"
#define sz(x) (int)(x.size())

//

void solve() {
	int n;
	cin>>n;
	vector<bool>vis(n+1,false);
	auto wk=[&](int l,int r,int q)->bool{
		vector<int>p;
		for(int i=l;i<=r;++i){
			if(!vis[i]){
				p.push_back(i);
			}
		}
		if(p.empty()){
			return false;
		}
		cout<<"? "<<sz(p)<<" "<<q<<endl;
		for(auto &x:p){
			cout<<x<<" ";
		}
		cout<<endl;
		for(int i=0;i<q;++i){
			cout<<i<<" ";
		}
		cout<<endl;
		int k;
		cin>>k;
		return (k!=q);
	};
	vector<int>res(n+1);
	for(int i=0;i<=n;++i){
		while(wk(1,n,i)){
			int L=1,R=n,g=-1;
			while(L<=R){
				int mid=(L+R)>>1;
				if(wk(1,mid,i)){
					R=mid-1;
					g=mid;
				}else{
					L=mid+1;
				}
			}
			res[g]=i;
			vis[g]=1;
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;++i){
		cout<<res[i]<<" "; 
	}
	cout<<endl;
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