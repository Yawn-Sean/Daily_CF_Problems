#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1194/D
//日期： 2024-3-6
//格式化： ctrl+shift+ a


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin>>tt;
	int n,k;
	while(tt--) {
		cin>>n>>k;
		
		if(k%3!=0) {
			if(n%3==0) cout<<"Bob"<<endl;
			else cout<<"Alice"<<endl;
		} 
		else {
			n%=(k+1);
			if(n%3==0 && n!=k) cout<<"Bob"<<endl;
			else cout<<"Alice"<<endl;
		}
	}

	return 0;
}


