#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
int a[N];
int n,d;
void solve(){
	cin>>n>>d;
	vector<int>v,v0,ans;
	for(int i=31;i>=0;i--){
		if(n&(1<<i)){
			v.push_back(i);
			v0.push_back(1);
		}
	}
	int x=1;
	for(auto t:v){
		for(int i=1;i<=t;i++){
			ans.push_back(x);
			//x++;
		}
		x+=d;
	}
	for(auto t:v0){
		//x+=d;
		ans.push_back(x);
		x+=d;
	}
	cout<<ans.size()<<"\n";
	for(auto t:ans){
		cout<<t<<" ";
	}
	cout<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
