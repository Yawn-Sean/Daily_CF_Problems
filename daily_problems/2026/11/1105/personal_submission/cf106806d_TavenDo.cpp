#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//

void solve() {
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	LL S=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]==a[i-1]){
			cout<<"possible"<<endl;
			return;
		}
		if(i>=3 and a[i]<=S){
			cout<<"possible"<<endl;
			return;
		}
		S+=a[i];
	}
	cout<<"impossible"<<endl;
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