#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
ll a,b,n,s[N],l,m,t;
//操作具有二分性，对端点进行二分即可
bool check(ll r){
	return (s[r]-s[l-1])<=m*t;
}
int main(){
	cin>>a>>b>>n;
	for(int i=1;i<N;i++){
		ll num=a+(i-1)*b;
		s[i]=s[i-1]+num;
	}
	for(int i=1;i<=n;i++){
		int l1;
		cin>>l1>>t>>m;
		l=l1;
		ll r=(t-a)/b+1,ans=-1;
		while(l1<=r){
			ll mid=(l1+r)>>1;
			if(check(mid)){
				ans=mid;
				l1=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}

}