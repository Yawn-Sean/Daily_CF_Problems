#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N=100005;
PII a[N];
int n, t_L[N]; 
LL ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x>a[i].y) swap(a[i].x, a[i].y);
	}
	sort(a+1, a+1+n);
	for(int i=n;i>=1;i--) t_L[i]=max(a[i].y, t_L[i+1]);
	for(int i=1;i<=n;i++){
		ans=max({ans, 1LL*a[i].x*a[i].y, 2LL*a[i].x*min(a[i].y, t_L[i+1])});
	}
	cout<<ans/2<<'.'<<ans%2*5;
}
