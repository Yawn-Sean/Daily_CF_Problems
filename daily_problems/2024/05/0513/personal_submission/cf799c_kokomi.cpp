#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
//数据范围太大，用不了dp
//两种情况： 一种分别取最大 另一种买其中一个，再找用剩下的钱可以买到的最大，这个可以用树状数组维护
int n,c,d;
int C[N],D[N];
int ans;
int lowbit(int x){
	return x&(-x);
}

void add(int *C,int x,int d){
	for(;x<=100000;x+=lowbit(x)) C[x]=max(C[x],d);
}

int q(int *C,int x){
	int mx=-1e6;
	for(;x;x-=lowbit(x)) mx=max(mx,C[x]);
	return mx;
}

int main(){
	cin>>n>>c>>d;
	memset(C,-1e6,sizeof(C)),memset(D,-1e6,sizeof(D));
	ans=0;
	for(int i=1;i<=n;i++){
		int tmp,b,p;
		string s;
		cin>>b>>p>>s;
		if(s=="C"){
			if(p>c) continue;
			tmp=max(q(C,c-p),q(D,d));
			add(C,p,b);
		}else{
			if(p>d) continue;
			tmp=max(q(C,c),q(D,d-p));
			add(D,p,b);
		}
//		cout<<tmp<<endl;
		ans=max(ans,tmp+b);
	}
	cout<<ans<<endl;

}