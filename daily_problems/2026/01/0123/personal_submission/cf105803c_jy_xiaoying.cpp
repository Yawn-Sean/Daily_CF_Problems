#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/105803/problem/C

//    2026-1-23-(思维)- cfgym105803C 
//

//日期： 2026-1-23 
//格式化： ctrl+shift+ a

typedef long long ll;

const int MAX=1e6+10;

int tt;
ll n,k;
ll nums[MAX];

ll mod[MAX];   // 模数的次数 

void solve(){
	if(k==n-1){
		fill(mod,mod+n+1,0);
		
		ll ans=0;
		for(int i=0;i<n;i++){
			mod[nums[i]%n]++;
		}
		for(int i=0;i<n;i++){
			ans+=(n-i)%n * mod[i];
		}
		
		ll cur=ans;
		for(int r=0;r<n;r++){
			cur+=n;
			cur-=n*mod[(r+1)%n];
			
			ans=min(ans,cur);
		}
		
		cout<<ans<<endl;
	}
	
	else{
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=nums[i];
			sum%=n;
		}
		cout<<(n-sum)%n<<endl;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 

    cin>>tt;
    while(tt--){
    	cin>>n>>k;
    	for(int i=0;i<n;i++) cin>>nums[i];
    	solve();
	}
	
    return 0;
}

/*



*/

