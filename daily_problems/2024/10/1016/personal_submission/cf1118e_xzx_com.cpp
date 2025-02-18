#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=1000+10;
int a[N],s[N];
int f[N][N];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--) {
        int n,k;cin>>n>>k;
        if(n<=k*k-k){
        	cout<<"YES"<<'\n';
        	int x=1,y=2,tmp=k,flag=0;
        	while(x!=tmp){
        		for(int y=x+1;y<=tmp;y++){
        			cout<<x<<' '<<y<<'\n';
        			n--;
        			if(n==0){flag++;break;}
        			cout<<y<<' '<<x<<'\n';
        			n--;
        			if(n==0){flag++;break;}
				}
				if(flag!=0)break;
				x++;
        	}
		}else {
			cout<<"NO"<<'\n';
		}
    }
    return 0;
}
