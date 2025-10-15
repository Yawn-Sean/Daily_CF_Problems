#include<bits/stdc++.h> 
using namespace std;

//链接：https://codeforces.com/problemset/problem/258/C
//日期： 2024-2-29
//格式化： ctrl+shift+ a

typedef long long ll;
typedef vector<int> vv;

const int MAX=1e5+10;
const int inf=1e5+5;
const int mod=1e9+7;

int cnt[MAX];  // 数组中 >=i 的个数 
int n;
int nums[MAX]; 
vector<vv> pri=vector<vv>(MAX,vv());

int big=1;

ll poww(ll x,int y){
	ll ans=1;
	if(x==1) return 1;
	if(y==0) return 1;
	
	while(y){
		if(y & 1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y/=2;
	}
	return ans;
}

void f(){
	ll ans=1;
	for(int i=2;i<=big;i++){
		ll tmp=1;
		int k=pri[i].size();
		for(int j=0;j<k-1;j++){
			int x=cnt[pri[i][j]]-cnt[pri[i][j+1]];
			tmp=(tmp*poww(j+1,x))%mod;
		}
		int x=cnt[pri[i][k-1]]-cnt[inf];
		tmp=(tmp*poww(k,x))%mod;
		
		ll tmp2=1;
		for(int j=0;j<k-2;j++){
			int x=cnt[pri[i][j]]-cnt[pri[i][j+1]];
			tmp2=(tmp2*poww(j+1,x))%mod;
		}

	    x=cnt[pri[i][k-2]]-cnt[inf];
		tmp2=(tmp2*poww(k-1,x))%mod;
		
		ans=(ans+tmp-tmp2+mod)%mod;
	}
	
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0;i<MAX;i++) cnt[i]=0;
	for(int i=0;i<n;i++){
		cin>>nums[i];
		cnt[nums[i]]++;
		big=max(big,nums[i]);
	}
	
	for(int i=MAX;i>=0;i--) cnt[i]+=cnt[i+1],pri[i].push_back(1);
	
	for(ll i=2;i<MAX;i++){
		pri[i].push_back(i);

		for(ll j=2*i;j<MAX;j+=i){
			pri[j].push_back(i);
		}
	}
	
	f();

	return 0;
}


