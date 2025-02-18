#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	if(n>(long long)k*(k-1)) cout<<"no";
	else{
        cout<<"yes\n";
		int cnt=0;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				if(cnt<n) cout<<i<<" "<<j<<'\n', cnt++;
				else return 0;
				if(cnt<n) cout<<j<<" "<<i<<'\n', cnt++;
				else return 0;
			}
		}
	}
	return 0;
}
