#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/105427/problem/A

//    2026-1-24-(模拟发现规律)- cfgym105427A
//

//日期： 2026-1-24 
//格式化： ctrl+shift+ a

typedef long long ll;

ll n,k;

void solve(){
	vector<ll> len;
	vector<ll> cnts;
	len.push_back(k+1),cnts.push_back(1LL);
	
	while(len.back()<n && cnts.size()<k){
		len.push_back(k*len.back()+1);
		cnts.push_back(k*cnts.back()+1);
	}
	
	ll ans=max(0LL,n-len.back());
	n-=ans;
	
	int arr_len=len.size();
	
	for(int i=arr_len-1;i>=0;i--){
		ans+=n/len[i]*cnts[i];
		n%=len[i];
	}
	
	cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 

    cin>>n>>k;
    solve();
    
    return 0;
}

/*



*/

