/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::vector<int> KMP(std::vector<int> a,std::vector<int> b){
    int n=a.size(),m=b.size();
	a.insert(a.begin(),0),b.insert(b.begin(),0);
	std::vector<int> q(n+1,0);
    std::vector<int> ne(m+1,0);
	for(int i=2,j=0;i<=m;i++){
		while(j and b[j+1]!=b[i]) j=ne[j];
		if(b[j+1]==b[i]) j++;
		ne[i]=j;
	}
	for(int i=1,j=0;i<=n;i++){
		while(j and a[i]!=b[j+1]) j=ne[j];
		if(a[i]==b[j+1]) j++;
		q[i]=j;
		if(j==m) j=ne[j];
	}
	return q;
}

constexpr int M=10000;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2),b(m+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=m;i++) std::cin>>b[i];
    std::vector<int> p,s;
    for(int i=2;i<=n;i++) p.pb((a[i]-a[i-1]+M)%M);
    for(int i=2;i<=m;i++) s.pb((b[i]-b[i-1]+M)%M);

    auto res=KMP(p,s);

    std::vector<int> cnt(M+2);

    for(int i=0;i<n;i++){
        if(res[i]==m-1){
            cnt[(b[1]-a[i-m+2]+M)%M]++;
        }
    }
    int mx=0,k=0;
    for(int i=0;i<M;i++){
        if(cnt[i]>mx){
            k=i,mx=cnt[i];
        }
    }
    std::cout<<k<<" "<<mx<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
