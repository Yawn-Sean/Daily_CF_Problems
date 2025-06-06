#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/621/E
//日期： 2024-3-6
//格式化： ctrl+shift+ a

typedef long long ll;
typedef vector<ll> vv;
const ll mod=1e9+7;

int n,b,k,x;   //有n个数字，b个数字块要填  %x==k
ll cnt[10]; 

vector<vv> multiply(vector<vv> m1,vector<vv> m2){
	int p1=m1.size();   int len=m1[0].size();
	int p2=m2[0].size();  
	vector<vv> ans(p1,vv(p2,0));
	for(int i=0;i<p1;i++){
		for(int j=0;j<p2;j++){
			ll tmp=0;
			for(int id=0;id<len;id++){
				tmp+=m1[i][id]*m2[id][j];
				tmp%=mod;
			}
			ans[i][j]=tmp;
		}
	}
	return ans;
}

vector<vv> ppow(vector<vv> base,int nn){
	int len=base.size();
	vector<vv> ans(len,vv(len,0));
	for(int i=0;i<len;i++){
		ans[i][i]=1;
	}
	while(nn){
		if(nn & 1) ans=multiply(ans,base);
		base=multiply(base,base);
		nn/=2;
	}
	return ans;
}

int f(){
	
	vector<vv> star(1,vv(x,0));
	for(int i=1;i<=9;i++){
		star[0][i%x]+=cnt[i];
	}
	if(b==1) return star[0][k];
	
	vector<vv> base(x,vv(x,0));
	for(int i=0;i<x;i++){
		for(int j=0;j<=9;j++){
			int id=(i*10+j)%x;
			base[i][id]+=cnt[j];
			base[i][id]%=mod;
		}
	}
	
	vector<vv> tmp=ppow(base,b-1);
	tmp=multiply(star,tmp);
	return tmp[0][k];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>b>>k>>x;
    int tmp;
    for(int i=0;i<n;i++){
    	cin>>tmp;
    	cnt[tmp]+=1;
	}
	
	tmp=f()%mod;
	cout<<tmp<<endl;

	return 0;
}


