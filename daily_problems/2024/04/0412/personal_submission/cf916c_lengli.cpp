// Problem: C. Jamie and Interesting Graph
// Contest: Codeforces - Codeforces Round 457 (Div. 2)
// URL: https://codeforces.com/problemset/problem/916/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

long long mul( long long a , long long b , long long md ) {
    return ( a * b - (long long)( (long double)a / md * b + 0.5 ) * md + md ) % md;
}
long long Pow( long long x , long long a , long long md ) {
    long long cur = x % md , ans = 1;
    while( a ) {
        if( a & 1 ) ans = mul( ans , cur , md );
        cur = mul( cur , cur , md ) , a >>= 1;
    }
    return ans;
}

const int ck[] = {2,3,5,7,11,13,17,19,23,29,31,37,41} , _l = 10;
bool miLLer( long long n ) {
    if( n == 1 ) return false;
    long long t = n - 1; int cn = 0;
    while( !( t & 1 ) ) t >>= 1 , ++ cn;
    for( int i = 0 ; i < _l ; ++ i ) {
        if( n == ck[i] ) return true;
        long long a = Pow( ck[i] , t , n ) , nex = a;
        for( int j = 1 ; j <= cn ; ++ j ) {
            nex = mul( a , a , n );
            if( nex == 1 && a != 1 && a != n - 1 ) return false;
            a = nex;
        }
        if( a != 1 ) return false;
    }
    return true;
}



void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a;
	a.pb(1),a.pb(n);
	for(int i=2;i<=n;i++) a.pb(i);
	m-=n-2;
	
	vector<array<int,3>> res;
	int sum=0;
	for(int i=0;i<n-2;i++){
		res.pb({a[i],a[i+1],2});
		sum+=2;
	}
	for(int i=0;i<n-1 and m>1;i++){
		for(int j=i+2;j<n and m>1;j++){
			m--;
			res.pb({a[i],a[j],100000007});
		}
	}
	for(int i=1;;i++){
		if(miLLer(i+sum)){
			res.pb({a[n-2],a[n-1],i});
			sum+=i;
			break;			
		}
	}
	cout<<2<<" "<<sum<<endl;
	for(auto [u,v,w]:res){
		cout<<u<<" "<<v<<" "<<w<<endl;
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
