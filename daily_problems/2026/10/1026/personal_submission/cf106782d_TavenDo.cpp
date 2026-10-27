#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())

//写递归

void solve() {
	int n;
	cin>>n;
	vector<int>res;
	auto wk=[&](auto self,int pos){
		if(pos>n){
			return;
		}
		res.push_back(pos);
		self(self,pos+1);
		res.push_back(pos);
		self(self,pos+1);
	};
	wk(wk,1);
	cout<<sz(res)<<endl;
	for(auto u:res){
		cout<<u<<" ";
	}
	cout<<endl;
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