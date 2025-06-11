#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int d=0;
LL h, n, L, R, res;
int main(){
	cin>>h>>n;
	L=1; R=1LL<<h;
	while(L<R){
		LL mid=L+R>>1;
		if(d){
			mid++;
			if(n<mid){
				res+=(R-L+1);
				R=mid-1;
			}else{
				res++;
				L=mid;
				d^=1;
			}
		}else{
			if(n>mid){
				res+=(R-L+1);
				L=mid+1;
			}else{
				res++;
				R=mid;
				d^=1;
			}
		}
	}
	cout<<res;
	return 0;
}
