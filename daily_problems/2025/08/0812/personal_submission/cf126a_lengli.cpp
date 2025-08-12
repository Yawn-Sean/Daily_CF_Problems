/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve() {
    int  t1,t2,t0,x1,x2,p1,p2;
    double t,minn=1e6;
	std::cin>>t1>>t2>>x1>>x2>>t0;
	double y1=x1,y2=x2;
	while(y1>=0&&y2>=0){
		t= double((t1*y1)+(t2*y2))/(y1+y2) ;
		if(t<t0){
			y1--;
		}else{
			if(t-t0<minn){
				minn=t-t0;
				p1=y1;	
				p2=y2;
			}
			y2--;
		}
	}
	std::cout<<p1<<" "<<p2<<"\n";
	return;
}


signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
