//Through thorns, to the stars.
//Raven ascends, never yielding, to meet a better self.
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"

//每次操作 总模三值不变

void solve() {
	int n;
	cin>>n;
	string a;
	cin>>a;
	a="!"+a;
	vector<int>b(n+1);
	for(int i=1;i<=n;++i){
		if(a[i]=='V'){
			b[i]=(b[i-1]+1)%3;
		}else{
			b[i]=(b[i-1]+2)%3;
		}
	}
	bool f=false;
	for(int i=1;i<=n;++i){
		if(a[i]==a[i-1]){
			f=true;
		}
	}
	if(!f){
		cout<<n<<endl;
	}else{
		if(b[n]==0){
			cout<<2<<endl;
		}else{
			cout<<1<<endl;
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