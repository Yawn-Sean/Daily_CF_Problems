
//链接：

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5+10;
int n;
vector<int> v;
const int lim=(1<<17);
int M=17;

void f(){
	vector<int> cnt((1<<M),0);
	vector<int> cost((1<<M),0);
	
	for(int i:v){
		for(int j=0;(i>>j)>0;j++){
			cost[(i>>j)]+=j;
			cnt[(i>>j)]++;
			
			int tmp=(i>>j);
			if(j==0 || (i>>(j-1)) & 1){  //确保j位为1 才不会重复算 
				 for(int k=1;(tmp<<k)<lim;k++){
			        cost[(tmp<<k)]+=(j+k);
			        cnt[(tmp<<k)]++;
		        }
			}
		}
		
	}
	
	int ans=INT_MAX;
	for(int i=0;i<lim;i++){
		if(cnt[i]>=n){
			ans=min(ans,cost[i]);
		}
	}
	cout<<ans<<"\n";
}

int main(){
	cin>>n;
	v.clear();
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	
	f();
	return 0;
} 
