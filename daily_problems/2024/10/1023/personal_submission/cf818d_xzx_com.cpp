#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18;
int a[N],b[N];
map<int,int>q;
vector<int>c;
signed main() {
    int t=1;
    //cin >> t;
    while(t--) {
    	int n,k;cin>>n>>k;
    	for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k)b[i]=b[i-1]+1;
			else b[i]=b[i-1];
		}
		bool ok=0;
    	for(int i=1;i<=n;i++){
    		if(b[i]==0){
    			if(q[a[i]]==0&&a[i]!=k)c.push_back(a[i]);
    			q[a[i]]++;
			}else {
				q[a[i]]++;
				if(c.size()==0){
					ok=1;
					break;
				}else {
					if(a[i]==k){
						for(auto it=c.begin();it!=c.end();){
							if(q[*it]<b[i]){
								it=c.erase(it);
							}else it++;
						}
					}
				}
			}
		}
		if(ok==1||c.size()==0)cout<<-1<<'\n';
		else cout<<c[0]<<'\n';
    }
    return 0;
}
