#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1098/A

//    
 
//日期： 2024-3-12 
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long long ll;
typedef long double ld;
typedef vector<int> vv;

vector<vv> g;
int n;
ll val[MAX]; 
ll nums[MAX];
bool is_ok;

void dfs(int i,int h,ll sum){
	if(!is_ok) return ;
	
	if(h%2==0){    //高度为偶数 
		if(g[i].size()==0) {
			nums[i]=0;
			return ;
		}
		ll small=val[g[i][0]];
		for(int x:g[i]) small=min(small,val[x]);
		
		ll tmp=small-sum;
		if(tmp<0){
			is_ok=0;
			return ;
		}
		
		nums[i]=tmp;
		for(int x:g[i]){
			dfs(x,h+1,sum+tmp);
		}
	}
	else{
		nums[i]=val[i]-sum;
		if(g[i].size()==0) return ;
		for(int x:g[i]) {
			dfs(x,h+1,val[i]);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    g=vector<vv>(n+10,vv());
    int tmp;
    for(int i=2;i<=n;i++){
    	cin>>tmp;
    	g[tmp].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
    

     is_ok=1;
     nums[1]=val[1];
     for(int x:g[1]){
     	dfs(x,2,val[1]);
	 }
    
    
	if(!is_ok){
		cout<<-1<<endl;
	} 
	else{
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=nums[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*

5
1 1 1 1
1 -1 -1 -1 -1


*/

