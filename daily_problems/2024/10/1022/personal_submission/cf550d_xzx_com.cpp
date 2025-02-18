#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18;
PII a[N];
int b[N];
signed main() {
    int t=1;
    //cin >> t;
    while(t--) {
    	int k;cin>>k;
    	if(k%2==0)cout<<"NO"<<'\n';
    	else {
	    		cout<<"YES"<<'\n';
	        cout<<4*k-2<<' '<<(2*k-1)*k<<'\n';
	        for (int i=1;i<=k-1;i++) {
	            for (int j=1;j<=k-1;j++) {
	                cout<<i<<' '<<j+k-1<< '\n';
	                cout<<i+2*(k-1)<<' '<<j+3*(k-1)<<'\n';
	            }
	            if (i%2==0) {
	                cout<<i-1<<' '<<i<<'\n';
	                cout<<i+2*(k-1)-1<<' '<<i+2*(k-1)<<'\n';
	            }
				cout<<i+k-1<<' '<<4*k-2<<'\n';
	            cout<<i+3*(k-1)<<' '<<4*k-3<<'\n';
	        }
			cout<<4*k-3<<' '<<4*k-2<<'\n';
		}
    }
    return 0;
}
