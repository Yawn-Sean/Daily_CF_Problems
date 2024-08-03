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

struct Node{
    int n;
	vector<vector<int>> a;
	void init(int nn){
        n=nn;a.clear();
		a.resize(n+2,vector<int> (n+2,0));
	}
	void updata(int x, int y, int d){
		for(int i = x; i <= n; i += (i&-i)){
			for(int j = y; j <= n; j += (j&-j)){
				a[i][j] += d;
			}
		}
	}
	
	int query(int x, int y){
		int res = 0;
		for(int i= x;i;i-=(i&-i)){
			for(int j=y;j;j-=(j&-j)){
				res += a[i][j];
			}
		}
		return res;
	}
	void add(int a,int b,int c,int d,int k){
		updata(a,b,k);
		updata(a,d+1,-k);
		updata(c+1,b,-k);
		updata(c+1,d+1,k);
	}
}tr;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<char>> g(n+2,vector<char> (n+2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>g[i][j];
    
    vector<int> hh(n+1,0),ll(n+1,0);
    tr.init(n);
    for(int i=1;i<=n;i++){
        bool flag=1;
        int l=-1,r=-1;
        for(int j=1;j<=n;j++) {
            if(g[i][j]=='B'){
                flag=0;
                if(l==-1) l=r=j;
                else r=j;
            }
        }
        hh[i]=flag;
        if(l==-1 and r==-1) tr.add(max(1,i-k+1),1,i,n,1);
        else if(r-l+1<=k) tr.add(max(1,i-k+1),max(1,r-k+1),i,l,1);
    }

    for(int j=1;j<=n;j++){
        bool flag=1;
        int l=-1,r=-1;
        for(int i=1;i<=n;i++) {
            if(g[i][j]=='B') {
                flag=0;
                if(l==-1) l=r=i;
                else r=i;
            }
        }
        ll[j]=flag;
        if(l==-1 and r==-1) tr.add(1,max(j-k+1,1),n,j,1);
        else if(r-l+1<=k) tr.add(max(1,r-k+1),max(1,j-k+1),l,j,1);
    }
    for(int i=1;i<=n;i++) hh[i]+=hh[i-1],ll[i]+=ll[i-1];

    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int ans=tr.query(i,j);
            if(i-1>=1) ans+=hh[i-1];
            if(i+k<=n) ans+=hh[n]-hh[i+k-1];
            if(j-1>=1) ans+=ll[j-1];
            if(j+k<=n) ans+=ll[n]-ll[j+k-1];
            res=max(res,ans);
        }
    }
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
