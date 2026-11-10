#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
//

void solve() {
	string a;
	cin>>a;
	int n=sz(a);
	a="!"+a;
	int res=-1;
	for(int i=2;i<=n;++i){
		if((n%i)==0){
			int p=n/i;
			bool f=true;
			for(int j=0;j<n;j+=p){
				for(int k=1;k<=p;++k){
					if(a[k]!=a[j+k]){
						f=false;
					}
				}
			}
			if(f){
				res=i;
			}
		}
	}
	if(res==-1){
		cout<<1<<endl;
		for(int i=1;i<=n;++i){
			cout<<a[i];
		}
	}else if(res==n){
		cout<<n<<endl;
		for(int i=1;i<=n;++i){
			cout<<a[i]<<" ";
		}
	}else{
		cout<<2<<endl;
		cout<<a[1]<<" ";
		for(int i=2;i<=n;++i){
			cout<<a[i];
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