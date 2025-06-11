//链接：https://codeforces.com/problemset/problem/1118/E

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k;

void prit(int x,int y){
	cout<<x<<" "<<y<<endl;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	if(n>k*(k-1)){
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	ll cnt=n;
	for(int i=1;i<k;i++){
		for(int j=i+1;j<=k;j++){
			if(cnt==0) return 0;
			else{
				cnt--;
				prit(i,j);
			}
			
			if(cnt==0) return 0;
			else{
				cnt--;
				prit(j,i);
			}
		}
	}
	
	return 0;
} 
