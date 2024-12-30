#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long ll;
int n,T;
struct Node{
	int a,t;
	bool operator<(const Node x){
		return t<x.t;
	}
}node[N];
//感觉就是贪心？
void solve(){
	cin>>n>>T;
	for(int i=1;i<=n;i++) cin>>node[i].a;
	ll rs=0,ls=0;
	double ans=0;
	for(int i=1;i<=n;i++){
		cin>>node[i].t;
		node[i].t-=T;
		if(node[i].t<0) ls-=(ll)node[i].a*node[i].t;
		else if(node[i].t==0) ans+=node[i].a;
		else rs+=(ll)node[i].a*node[i].t;
	}
//	cout<<ls<<" "<<rs<<endl;
	sort(node+1,node+n+1);
	if(ls<rs){//正的多
		for(int i=1;i<=n;i++){
			if(node[i].t<0){
				ans+=node[i].a;
			}else if(node[i].t>0){
				if((ll)node[i].t*node[i].a<=ls){
					ls-=(ll)node[i].t*node[i].a;
					ans+=node[i].a;
				}else{
					ans+=(double)ls/node[i].t;
					break;
				}

			}
		}
	}else{
		for(int i=n;i>=1;i--){
			if(node[i].t>0){
				ans+=node[i].a;
			}else if(node[i].t<0){
				if((ll)-node[i].a*node[i].t<=rs){
					rs+=(ll)node[i].a*node[i].t;
					ans+=node[i].a;
				}else{
					ans+=(double)rs/-node[i].t;
					break;
				}
			}
		}
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;
}
int main(){
	solve();
}