#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1468/D

//     2025-4-24-(二分答案+排序)-cf1468d 
//

//
//思路：

//日期： 2025-4-24 
//格式化： ctrl+shift+ a


typedef unsigned long long ull;
typedef long long ll;
typedef unordered_set<ull> mp;
const int MAX=2e5+10;
const ull base=1e9+7;

int t;
ll n,m,a,b;
ll nums[MAX];

bool is_ok(int cnt){
	ll times;
	if(a<=b){
		times=b-1;
	}
	else{
		times=n-b;
	}
	
	for(int i=cnt-1,j=1;i>=0;i--,j++){
		if(nums[i]+j>times) return 0;
	}
	return 1;
}

void solve() {
	int l=0,r=abs(a-b)-1;  r=min(r,(int)m);
	int ans;
	
	while(l<=r){
		int mid=(l+r)/2;
		if(is_ok(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    cin>>t;
    for(int i=0;i<t;i++){
    	cin>>n>>m>>a>>b;
    	for(int j=0;j<m;j++){
    		cin>>nums[j];
		}
		sort(nums,nums+m);
    	solve();
	}

	return 0;
}
/*

3
7 2 3 6
1 4
7 2 3 6
5 1
7 2 3 6
4 4



*/

