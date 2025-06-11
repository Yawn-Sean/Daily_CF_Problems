#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=6e5+10;
int a[N];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) {
        int n,m;cin>>n>>m;
        ld ans=-1e18,sum=0;
        while(m--){
        	int x,d;cin>>x>>d;
        	if(d>=0)sum+=n*x+d*(n-1)*n/2;
        	else sum+=n*x+d*min((n/2-1)*(n/2)/2+(n-n/2)*(n-n/2+1)/2,(n/2+1-1)*(n/2+1)/2+(n-n/2-1)*(n-n/2)/2);
        	//ans=max(ans,sum/n);
		}
		printf("%.15Lf\n",sum/n);
    }
    return 0;
}
