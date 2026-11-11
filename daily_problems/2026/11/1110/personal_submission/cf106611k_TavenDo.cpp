#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
//

void solve() {
	int n;
	cin>>n;
	vector<int>a(3*n+1);
	bool f=true;
	for(int i=1;i<=3*n;++i){
		cin>>a[i];
		if(a[i]!=i){
			f=false;
		}
	}
	if(f){
		cout<<0<<endl;
		return;
	}
	int L=1,R=3*n;
	for(int i=1;i<=3*n;++i){
		if(a[i]==i){
			++L;
		}else{
			break;
		}
	}
	for(int i=3*n;i>=1;--i){
		if(a[i]==i){
			--R;
		}else{
			break;
		}
	}
	int p=R-L+1;
	if(p<=2*n){
		cout<<1<<endl;
		cout<<L<<" "<<R<<endl;
		return;
	}
	int cL=L,tL=R-2*n+1;
	for(int i=L;i<=L+2*n-1;++i){
		if(a[i]<tL){
			++cL;
		}
	}
	if(cL==tL){
		cout<<2<<endl;
		cout<<L<<" "<<L+2*n-1<<endl;
		cout<<R-2*n+1<<" "<<R<<endl;
		return;
	}
	int cR=R,tR=L+2*n-1;
	for(int i=R;i>=R-2*n+1;--i){
		if(a[i]>tR){
			--cR;
		}
	}
	if(cR==tR){
		cout<<2<<endl;
		cout<<R-2*n+1<<" "<<R<<endl;
		cout<<L<<" "<<L+2*n-1<<endl;
		return;
	}
	cout<<3<<endl;
	cout<<1<<" "<<2*n<<endl;
	cout<<n+1<<" "<<3*n<<endl;
	cout<<1<<" "<<2*n<<endl;
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