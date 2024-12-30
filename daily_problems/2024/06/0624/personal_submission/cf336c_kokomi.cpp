#include<bits/stdc++.h>
using namespace std;
//高位是1，下面的要都是0
//从最大的可能的k去枚举
//把k位含1的全加进去算就行了，因为低位只要有0就可以消除
const int N = 1e5+10;
int a[N];
int b[N];
int main(){
	int n;
	cin>>n;
	int ans = 0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=30;k>=0;k--){
		int x = 1<<k;
		int y=x-1;
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]&x){
				y=y&a[i];
				b[ans++]=a[i];
			}
		}
		if(y==0){
			cout<<ans<<endl;
			for(int i=0;i<ans;i++){
				cout<<b[i]<<" ";
			}
			return 0;
		}
	}
}