#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//令f[i]=a[i]+b[i] 然后贪心选择

void solve() {
	int n;
	cin>>n;
	n*=2;
	vector<LL>a(n+1),b(n+1),c(n+1);
	LL tot=0,cur=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		tot+=a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	priority_queue<LL,vector<LL>,greater<LL>>pq;
	for(int i=n;i>=1;i-=2){
		pq.push(a[i]+b[i]);
		cur+=pq.top();
		pq.pop();
		pq.push(a[i-1]+b[i-1]);
	}
	cout<<tot-cur<<endl;
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