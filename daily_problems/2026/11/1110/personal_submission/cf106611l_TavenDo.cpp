#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"

//

void solve() {
	int n;
	string a;
	cin>>n>>a;
	a="!"+a;
	vector<int>res(n+2,0);   //2->肯定有  1->肯定没
	res[0]=1,res[n+1]=1;
	vector<bool>vis(n+1,false);
	queue<int>wk;
	for(int i=1;i<=n;++i){
		if(a[i]!='?'){
			res[i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]=='0'){
			res[i-1]=1;
			res[i+1]=1;
		}else if(a[i]=='2'){
			res[i-1]=2;
			res[i+1]=2;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]=='1' and !vis[i] and res[i-1]!=res[i+1]){
			vis[i]=1;
			wk.push(i);
		}
	}
	while(!wk.empty()){
		int u=wk.front();
		wk.pop();
		if(res[u+1]==0){
			res[u+1]=3-res[u-1];
			if(u+3<=n and !vis[u+2] and a[u+2]=='1' and res[u+3]==0){
				vis[u+2]=1;
				wk.push(u+2);
			}
		}else if(res[u-1]==0){
			res[u-1]=3-res[u+1];
			if(u-3>=1 and !vis[u-2] and a[u-2]=='1' and res[u-3]==0){
				vis[u-2]=1;
				wk.push(u-2);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(res[i]==1 and a[i]=='?'){
			++ans;
		}
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