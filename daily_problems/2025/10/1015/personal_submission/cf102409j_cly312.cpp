#include<bits/stdc++.h>
using ll=long long;
using namespace std;
void upd(ll a,ll b,ll c,ll d,ll &m){
	m=min(m,max({a,b,c,d})-min({a,b,c,d}));
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
    ll L;
	cin>>n>>L;
	vector<ll> x(n-1);
	for(ll &v:x) cin>>v;
	ll m=L;
	int i=0,k=1;
	for(int j=1;j<n-2;++j){
		while(i<j&&2*x[i]<x[j]) ++i;
		if(k<=j) k=j+1;
		while(k<n-1&&2*x[k]<L+x[j]) ++k;
		vector<int> ic,kc;
		if(i<j) ic.push_back(i);
		if(i) ic.push_back(i-1);
		if(k<n-1) kc.push_back(k);
		if(k-1>j) kc.push_back(k-1);
		for(int I:ic) for(int K:kc) upd(x[I],x[j]-x[I],x[K]-x[j],L-x[K],m);
	}
	cout<<m<<'\n';
}
