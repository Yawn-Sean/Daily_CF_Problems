//链接：https://codeforces.com/problemset/problem/487/A

#include<bits/stdc++.h>
using namespace std;

int x1,y1,z1;
int x2,y2,z2;
int a,b,c;

int f(int i,int j){
	int t1=y2-z1-j;    //杨过收到的伤害 
	int t2=y1+i-z2;     //怪收到的伤害 
	if(t2<=0) return INT_MAX/2;
	
	int sum=(x2+t2-1)/t2;
	int add=sum*t1-x1+1;      //杨过最后的 hp>0 
	return add<=0?0:add*a;
}

void solve(){
	int ans=INT_MAX;
	for(int i=0;i<=200;i++){
		for(int j=0;j<=200;j++){
			int tmp=f(i,j);
			tmp+=i*b+c*j;
			ans=min(ans,tmp);
		}
	}
	cout<<ans<<endl;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>x1>>y1>>z1;
	cin>>x2>>y2>>z2;
	cin>>a>>b>>c;
	
	solve();
	
	return 0;
} 
