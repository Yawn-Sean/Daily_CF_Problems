#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#define int long long
#define rg register
#define INF 0x7f7f7f7f
#define endl '\n'
#define pi 3.1415926
// #define OI_DEBUG
#define _IOFAST
using namespace std;
const int N=3e5+10;
int t,n,k,a[N],ans;
vector<int> q;
signed main(){
	#ifdef _IOFAST
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#endif
	#ifdef OI_DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	cin>>t;
	while(t--){
		cin>>n>>k;
		q.clear();
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			auto it = lower_bound(q.begin(),q.end(),a[i]);
			if(it==q.end()) q.emplace_back(a[i]);
			else *it=a[i];
			ans+=a[i];
			int len=q.size();
			if(q[len-1]>=len) cout<<ans+len*k<<" ";
			else cout<<ans+(len+len+k-1)*k/2<<" ";
		}
		cout<<endl;
	}
	return 0;
}