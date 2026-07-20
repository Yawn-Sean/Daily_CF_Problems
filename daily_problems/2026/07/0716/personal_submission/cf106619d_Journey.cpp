#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#define int long long
#define rg register
#define INF 0x7f7f7f7f
// #define endl '\n'
#define pi 3.1415926
// #define OI_DEBUG
// #define _IOFAST
using namespace std;
int t,pos,a,b,c;
signed main(){
	#ifdef _IOFAST
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#endif
	#ifdef OI_DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	cin>>t;
	while(t--){
		a=b=c=pos=0;
		int r;
		for(int i=1;i<=60;i++){
			int temp=1LL<<(i-1);
			cout<<"? "<<temp<<" "<<temp<<endl;
			cout.flush();
			cin>>r;
			c=c+(r<<(i-1));
			if(r&&!pos) pos=i;
		}
		a=1LL<<(pos-1);
		for(int i=1;i<=60;i++){
			if(i==pos) continue;
			int temp=(1LL<<(i-1))+a;
			cout<<"? "<<temp<<" "<<temp<<endl;
			cout.flush();
			cin>>r;
			a=a+(r<<(i-1));
		}
		b=a^c;
		if(a>b) swap(a,b);
		cout<<"! "<<a<<" "<<b<<endl;
		cout.flush();
	}
	return 0;
}