#include<bits/stdc++.h>
using namespace std;
int n, m, c, p, a[1005];
int main(){
	cin>>n>>m>>c;
	int l=0, r=n+1, mid=c/2;
     a[0] = -1, a[n+1] = c + 1;//
	while(m--){
		cin>>p;
		if(p<=mid){//是<=而不是< [1,c/2] [c/2+1,c]
			if(p>=a[l]){
				a[++l]=p;
				cout<<l<<endl;
			}else{
				int L=0, R=l+1;
				while(L+1<R){
					int t=L+R>>1;
					if(a[t]>p) R=t;
					else L=t;
				}
				a[R]=p;
				cout<<R<<endl;
			}
		}else{
			if(p<=a[r]){
				a[--r]=p;
				cout<<r<<endl;
			}else{
				int L=r-1, R=n+1;
				while(L+1<R){
					int t=L+R>>1;
					if(a[t]<p) L=t;
					else R=t;
				}
				a[L]=p;
				cout<<L<<endl;
			}
		}
		if(l+1==r) break;//没有空隙就装满了
	}
	return 0;
}
