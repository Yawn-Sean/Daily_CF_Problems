#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1000005];
int n, k;
bool check(int x){
	LL cnt=0, t0=2;
	for(int i=1;i<=n;i++){
        if(a[i]<x) continue;
		while(ceil(1.0*a[i]/t0)>x){
			t0<<=1;
		}
		int c1=0, c2=0;
		if(ceil(1.0*a[i]/t0)==x){
			c1=a[i]%t0;
			if(c1==0) c1=t0;
		}
		c2=(t0>>1);
        if(t0>2) t0>>=1;
		cnt+=max(c1, c2);
	}
	return cnt>=k;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int t;
	LL sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<k) cout<<-1;
	else
	{
		sort(a+1, a+1+n);
		int L=0, R=1e7+1;
		while(L+1<R){
			int mid=L+R>>1;
			if(check(mid)) L=mid;
			else R=mid;
		}
		cout<<L;
	}
	return 0;
}
