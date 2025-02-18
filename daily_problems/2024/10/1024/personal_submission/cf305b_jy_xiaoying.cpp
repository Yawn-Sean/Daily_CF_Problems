//链接：https://codeforces.com/problemset/problem/305/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll p,q;
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>p>>q;
    cin>>n;
    vector<ll> nums;
    for(int i=0;i<n;i++){
    	ll tmp;
    	cin>>tmp;
    	nums.push_back(tmp);
	}
	
	vector<ll> tmps;
	while(q){
		tmps.push_back(p/q);
		p%=q;
		swap(p,q);
	}
    
    
    if(n>1 && nums.back()==1){
    	nums.pop_back();
    	nums.back()+=1;
	}
	
	if(nums.size()!=tmps.size()){
		cout<<"NO"<<endl;
		return 0;
	}
	
	n=nums.size();
	for(int i=0;i<n;i++){
		if(nums[i]!=tmps[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	
	return 0;
}
