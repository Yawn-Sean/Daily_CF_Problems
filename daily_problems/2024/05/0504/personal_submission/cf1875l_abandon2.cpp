#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL c[N];
int n;
int lowbit(int x){
	return x&(-x);
}

struct node{
	int x,y;
	bool operator<(const node&v)const{
		if(x==v.x)
			return y<v.y;
		return x<v.x;
	}
}a[N];

void add(int k,LL x){
	if(k<0)return;
	for(int i=k;i<=n;i+=lowbit(i)){
		c[i]=max(c[i],x);
	}
}

LL ask(int k){
	LL sum=0;
	if(k<=0)return 0;
	for(int i=k;i>=1;i-=lowbit(i)){
		sum=max(sum,c[i]);
	}
	return sum;
}

void solve(){
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(i>=x){
			a[++len]={i-x,x};
		}
	}
	sort(a+1,a+1+len);
	// for(int i=1;i<=len;i++){
		// cout<<a[i].x<<" \n"[i==len];
	// }
	// for(int i=1;i<=len;i++){
		// cout<<a[i].y<<" \n"[i==len];
	// }
	LL mx=0;
	for(int i=1;i<=len;i++){
		//cout<<a[i].y<<'\n';
		
		LL s=ask(a[i].y-1);
		add(a[i].y,s+1);
		//cout<<s<<"\n";
		mx=max(mx,s+1);
	}
	cout<<mx<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
