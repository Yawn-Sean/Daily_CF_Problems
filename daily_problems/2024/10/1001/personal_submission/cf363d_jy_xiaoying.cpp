//链接：https://codeforces.com/problemset/problem/363/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,a;
const int MAX=1e5+10;
vector<int> peo=vector<int>(MAX,0);
vector<int> cost=vector<int>(MAX,0);

ll pre[MAX];  //前i个人的钱              这个没什么用 哈哈哈 
ll suf[MAX];   //后i辆车的花费 

bool check(int x){   //判断租x辆车是否可行 
     
	ll sum=0;              //防溢出 
	for(int i=0,j=m-x;i<x;i++,j++){
		sum+=max(cost[j]-peo[i],0);
	}
	return sum<=a;
}

void f(){
	int l=1,r=min(n,m);
	int ans=0;  
	ll money=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			money=max(suf[m-mid]-a,0LL);
			
			l=mid+1;
		}
		else r=mid-1;
	}
	
	cout<<ans<<" "<<money<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>a;
	for(int i=0;i<n;i++) cin>>peo[i];
	for(int j=0;j<m;j++) cin>>cost[j];
	
	sort(peo.begin(),peo.begin()+n,greater<int>());     //降序排序 
	sort(cost.begin(),cost.begin()+m,greater<int>());
	
	pre[0]=peo[0];    suf[m-1]=cost[m-1];
	for(int i=1;i<n;i++) pre[i]=pre[i-1]+peo[i];    //这个没什么用 哈哈哈  
	for(int i=m-2;i>=0;i--) suf[i]=suf[i+1]+cost[i];
	 
	f();

	return 0;
}
