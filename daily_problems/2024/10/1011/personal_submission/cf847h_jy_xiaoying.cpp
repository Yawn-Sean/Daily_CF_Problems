//链接：https://codeforces.com/problemset/problem/847/H

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

ll total;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	total=0;
	vector<ll> g(n,0);
	for(auto &x:g) {
		cin>>x;
		total+=x;
	}
     
     if(n==1){             //++++++++++++++++++++++++++++++++++++++
     	cout<<0<<endl;
     	return 0;
	 }
	 
	vector<ll> _left(n,0),l_tot(n,0);
	ll pre=-2e9, sum=0;
	for(int i=0; i<n; i++) {
		_left[i]=max(g[i],pre+1);
		pre=_left[i];
		l_tot[i]=(sum+=_left[i]);
	}

	vector<ll> _right(n,0),r_tot(n,0);
	ll suf=-2e9;
	sum=0;
	for(int i=n-1;i>=0;i--){
		_right[i]=max(suf+1,g[i]);
		suf=_right[i];
		r_tot[i]+=(sum+=_right[i]);
	}
	
	//cout<<total<<endl;
	ll ans=_right[0]+r_tot[1]-total;
	//cout<<ans<<endl;
	ans=min(ans,_left[n-1]+l_tot[n-2]-total);
	
	//cout<<ans<<endl;
	for(int i=1;i<n-1;i++){
		ans=min(ans,l_tot[i-1]+r_tot[i+1]+max(_left[i],_right[i])-total);
	}

    cout<<ans<<endl;
    
	return 0;
}
