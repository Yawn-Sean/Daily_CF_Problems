#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/492/D

//      二分 + lca                                                                   
//思路：     

//日期：  2024-4-8 
//格式化： ctrl+shift+ a


const int MAX=1e5+10;
typedef long long ll;

int n;
ll x,y;
ll nums[MAX];
int ans[MAX];
string s[3]={"Vanya","Vova","Both"}; 
           //  0        1      2

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

int f(ll k){
	if(x==y) return 2;
	
	ll lcm=x*y/gcd(x,y);
	ll t1=lcm/x;
	ll t2=lcm/y;
	
	ll l=1,r=1e18;
	ll res;
	while(l<=r){
		ll mid=l+(r-l)/2;
		ll cnt=mid/t1+mid/t2;
		
		if(cnt>=k){
			res=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	
	bool flag1=(res%t1==0)?1:0;
	bool flag2=(res%t2==0)?1:0;
	
	if(flag1 && flag2) return 2;
	
	if(flag1) return 0;
	return 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    cin>>x>>y;
    for(int i=0;i<n;i++){
    	cin>>nums[i];
	}
	for(int i=0;i<n;i++){
		ans[i]=f(nums[i]);
	}
	for(int i=0;i<n;i++){
		cout<<s[ans[i]]<<endl;
	}

	return 0;
}
/*


*/

