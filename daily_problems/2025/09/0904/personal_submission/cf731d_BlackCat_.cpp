#include<bits/stdc++.h>
#define endl '\n';
using i64= long long;
void solve(){
	int n,m;
	std::cin>>n>>m;
	std::vector<std::vector<int>> a(n);
	for(int i=0;i<n;i++){
		int l;
		std::cin>>l;
		for(int j=0;j<l;j++){
			int x;
			std::cin>>x;
			x--;
			a[i].push_back(x);
			
		}
	}
	i64 ans=0;
	int flag=0;
	std::vector<int> pre(5e5+10,0);
	std::queue<std::array<int,3>> q;
	std::vector<int> vis(5e5+10,0);
	q.push({0,n,1});
	i64 cur=0;
	while(!q.empty()){
		auto [l,r,len]=q.front();
		q.pop();
		if(l==r){
			continue;
		}
		if(vis[len]==0){
			vis[len]=1;
			cur+=pre[len-1];
		}
		int f=0;
		for(int i=l;i<r;i++){
			if(a[i].size()<len){
				if(f){
					flag=1;
					std::cout<<-1<<endl;
					return ;
				}
				l=i+1;
			}
			else{
				f=1;
			}
		}
		if(l==r){
			continue;
		}
		int st=(a[l][len-1]+cur)%m;
		int ls=st;
		f=0;
		for(int i=l+1;i<r;i++){
			if((a[i][len-1]+cur)%m>=ls){
				ls=(a[i][len-1]+cur)%m;
			}
			else{
				if(f){
					flag=1;
					std::cout<<-1<<endl;
					return ;
				}
				f=1;
				ls=(a[i][len-1]+cur)%m;
			}
		}
		if(f){
			if(ls>=st){
				flag=1;
				std::cout<<-1<<endl;
				return ;
			}
			if(pre[len]==0){
				pre[len]=m-(a[l][len-1]+cur)%m;
			}
			pre[len]=std::lcm(pre[len],m-(a[l][len-1]+cur)%m)%m;
		}
		
		ls=st;
		int ll=l;
		for(int i=l+1;i<r;i++){
			if((a[i][len-1]+ans)%m!=ls){
				q.push({ll,i,len+1});
				ll=i;
			}
			ls=(a[i][len-1]+ans)%m;
		}
		if(ll+1!=r){
			q.push({ll,r,len+1});
		}
	}
	for(auto x:pre){
		ans+=x;
	}
	if(flag){
		std::cout<<-1<<endl;
	}
	else{
		std::cout<<ans<<endl;
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	solve();
}
