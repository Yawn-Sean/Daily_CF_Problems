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
#define endl '\n'
#define pi 3.1415926
// #define OI_DEBUG
#define _IOFAST
using namespace std;
const int N=2e5+10;
int t,n,a[N],b[N],c[N];
inline int lowbit(int x){
	return x & (-x);
}
inline void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)) c[i]+=y;
	return;
}
inline int query(int x){
	int sum=0;
	for(int i=x;i;i-=lowbit(i)) sum+=c[i];
	return sum;
}
inline int sum(int x,int y){
	return query(y)-query(x-1);
}
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
		cin>>n;
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]=i;
		for(int i=2;i<=n;i++) add(b[i],1);
		int ans=b[1]-1;
		for(int i=2;i<=n;i++){
			add(b[i],-1);
			if(b[i]>b[i-1]) ans+=sum(b[i-1],b[i]);
			else ans+=sum(1,b[i])+sum(b[i-1],n);
		}
		cout<<ans<<endl;
	}
	return 0;
}