/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

std::vector<int> KMP(std::vector<std::pair<int,char>> a,std::vector<std::pair<int,char>> b){
    int n=a.size(),m=b.size();
    a.insert(a.begin(),std::make_pair(0,'*'));
    b.insert(b.begin(),std::make_pair(0,'*'));
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

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::pair<int,char>> a,b;
    for(int i=1;i<=n;i++){
        int x;
        char c,tmp;
        std::cin>>x>>tmp>>c;
        if(i==1) a.pb(std::make_pair(x,c));
        else if(a.back().second==c) a.back().first+=x;
        else a.pb(std::make_pair(x,c));
    }
    for(int i=1;i<=m;i++){
        int x;
        char c,tmp;
        std::cin>>x>>tmp>>c;
        if(i==1) b.pb(std::make_pair(x,c));
        else if(b.back().second==c) b.back().first+=x;
        else b.pb(std::make_pair(x,c));
    }


    std::pair<int,char> st,ed;

    auto get=[&](int i,int k)->int{
        if(i+k+1>=a.size()) return 0;
        auto [vl,tl]=a[i];
        auto [vr,tr]=a[i+k+1];
        if(tl!=st.second or tr!=ed.second) return 0;
        return vl>=st.first and vr>=ed.first;
    };

    i64 res=0;
    if(b.size()==1){
        auto [x,c]=b[0];
        for(auto [v,t]:a){
            if(t==c and v>=x) res+=v-x+1;
        }
    }else if(b.size()==2){
        st=b[0],ed=b.back();
        for(int i=0;i<a.size();i++) res+=get(i,0);
    }else{
        st=b[0],ed=b.back();
        b.pop_back();b.erase(b.begin(),b.begin()+1);

        auto q=KMP(a,b);

        for(int i=2;i<=a.size();i++){
            if(q[i]==b.size()){
                res+=get(i-q[i]-1,b.size());
            }
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
