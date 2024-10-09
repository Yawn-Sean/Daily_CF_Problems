#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n;
	cin>>n;
    bool f=1;
	for(int i=0;i<60;i++){
		LL a1=(1LL<<i)-1, l=0, r=sqrt(2*n)+1+1;
        if(i!=0) r=min(max(1LL, n/a1)+1, r);
		while(l+1<r){
			LL m=(l+r)>>1;
			if(a1*m+m*(m-1)/2<=n) l=m;
			else r=m;
		}
		if(a1*l+l*(l-1)/2==n&& l%2) f=0, cout<<(a1+1)*l<<'\n';
	}
    if(f) cout<<-1;
	return 0;
}
