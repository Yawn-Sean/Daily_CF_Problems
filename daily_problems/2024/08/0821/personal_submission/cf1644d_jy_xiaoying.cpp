//链接：https://codeforces.com/problemset/problem/1644/D
//  2024-8-21         ctrl+shift+A

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m,q,k;    //q-颜色的种类，k种操作
const int MAX=2e5+10;
int xs[MAX];
int ys[MAX];
bool visx[MAX];
bool visy[MAX];
const int mod=998244353;

ll ans[MAX];

ll f() {
	ll res=1;
	int xx=0,yy=0;
	for(int i=k-1; i>=0; i--) {
		int a=xs[i],b=ys[i];
		if((yy<m && !visx[a]) || (xx<n && !visy[b])) {
			res=res*q%mod;
			if(!visx[a]) {
				visx[a]=1;
				xx++;
			}
			if(!visy[b]) {
				visy[b]=1;
				yy++;
			}
		}
	}

	for(int i=0; i<k; i++) {
		int a=xs[i],b=ys[i];
		visx[a]=visy[b]=0;
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin>>t;

	for(int j=0; j<t; j++) {
		cin>>n>>m>>q>>k;
		for(int i=0; i<k; i++) {
			cin>>xs[i]>>ys[i];
			xs[i]--;
			ys[i]--;
		}
		ans[j]=f();
	}
	
	for(int j=0;j<t;j++){
		cout<<ans[j]<<endl;
	}


	return 0;
}
