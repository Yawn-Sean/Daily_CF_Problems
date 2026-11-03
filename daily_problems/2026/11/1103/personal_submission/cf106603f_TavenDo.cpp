#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//随机数据乱搞，肯定是若干个性价比最高+若干个体积最小的塞缝
struct info{
	LL s,v;
};
bool cmp1(info &a,info &b){
	if(a.v*b.s!=b.v*a.s){
		return a.v*b.s>b.v*a.s;
	}else{
		return a.s<b.s;
	}
}
bool cmp2(info &a,info &b){
	if(a.s!=b.s){
		return a.s<b.s;
	}else{
		return a.v>b.v;
	}
}
const int MXN=30;  //这个阈值本来300跑的有点极限
void solve() {
	int n;
	cin>>n;
	vector<info>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i].s>>a[i].v;
	}
	vector<info>B;
	vector<LL>dp(n+1);
	sort(a.begin()+1,a.begin()+1+n,cmp1);
	for(int i=1;i<=min(n,MXN);++i){
		B.push_back(a[i]);
	}
	sort(a.begin()+1,a.begin()+1+n,cmp2);
	for(int i=1;i<=min(n,MXN);++i){
		B.push_back(a[i]);
	}
	for(int i=1;i<=n;++i){
		for(auto &U:B){
			if(i>=U.s){
				dp[i]=max(dp[i],dp[i-U.s]+U.v);
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout<<dp[i]<<" ";
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