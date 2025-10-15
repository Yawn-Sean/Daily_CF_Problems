#include<bits/stdc++.h>
void solve(){
	int n;
	std::cin>>n;
	int a,b;
	std::cin>>a>>b;
	std::vector<std::pair<int,int>> v(n);
	for(int i=0;i<n;i++){
		std::cin>>v[i].first;
		v[i].second=i;
	}
	if(a==b){
		for(int i=0;i<a;i++){
			std::cout<<1<<" ";
		}
		for(int i=0;i<b;i++){
			std::cout<<2<<" ";
		}
		return;
	}
	std::vector<int> ans(n);
	
	if(a<b){
		std::sort(v.begin(),v.end(),[&](auto x,auto y){
			if(x.first==y.first){
				return x.second<y.second;
			}
			else{
				return x.first>y.first;
			}
		});
		for(int i=0;i<n;i++){
			if(i<a){
				ans[v[i].second]=1;
			}
			else{
				ans[v[i].second]=2;
			}
		}
	}
	else{
		std::sort(v.begin(),v.end(),[&](auto x,auto y){
			if(x.first==y.first){
				return x.second>y.second;
			}
			else{
				return x.first>y.first;
			}
		});
		for(int i=0;i<n;i++){
			if(i<b){
				ans[v[i].second]=2;
			}
			else{
				ans[v[i].second]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		std::cout<<ans[i]<<" \n"[i==n-1];
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	solve();
}
