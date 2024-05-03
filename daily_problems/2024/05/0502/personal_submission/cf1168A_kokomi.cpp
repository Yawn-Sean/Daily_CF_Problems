#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int n,m;
int a[N],b[N];
//答案具有二分性
//因为是可以任选的，所以我们贪心的将a1变成能变成的最小值
//对于后面的每一个ai,看看能不能在mid次内变成比ai-1更小

bool check(int mid){
	if(mid == m) return 1;
	memcpy(b,a,sizeof a);
	int tmp = (b[1]+mid)%m,i;
	if(tmp<b[1]) b[1]=0;
	for(int i=2;i<=n;i++){
		tmp=(b[i]+mid)%m;
		if(tmp<b[i]){//过了m
			if(0<=b[i-1]&&b[i-1]<=tmp){
				b[i]=b[i-1];
			}else if(b[i]<=b[i-1]&&b[i-1]<m){
				b[i]=b[i-1];
			}
		}else{
			if(b[i]<=b[i-1]&&b[i-1]<=tmp){
				b[i]=b[i-1];
			}else if(tmp<b[i-1]){
				return 0;//不可能比前一个数大
			}
		}
	}
	return 1;
	
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=0,r=m;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
int main(){
	solve();
}