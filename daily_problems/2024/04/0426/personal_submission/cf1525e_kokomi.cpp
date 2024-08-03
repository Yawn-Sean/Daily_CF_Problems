#include<bits/stdc++.h>
using namespace std;
//求点数的期望，可以将每个点的期望相加
//就是求点被覆盖对应的排列数
//正难则反，求未被征服的期望 
const int MOD = 998244353;
int n,m;
int a[50010][22];
int pow(int x,int y){
	int tmp=1;
	while(y){
		if(y&1) tmp=1LL*tmp*x%MOD;
		y>>=1;
		x=1LL*x*x%MOD;
	}
	return tmp;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			a[j][x]++;
		}
	}
	int ed=0,fac=1;
	for(int i=1;i<=n;i++) fac=1LL*fac*i%MOD;
	for(int i=1;i<=m;i++){
		int sum=0,ans=1;
		for(int j=n;j>=1;j--){
			sum+=a[i][j+1],ans=1LL*ans*sum%MOD,sum--;
		}
		ed=(ed+1-1LL*pow(fac,MOD-2)*ans%MOD+MOD)%MOD;
	}
	cout<<ed<<endl;
}
int main(){
	solve();
}