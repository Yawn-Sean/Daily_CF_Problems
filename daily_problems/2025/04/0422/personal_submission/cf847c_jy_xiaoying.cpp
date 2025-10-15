#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/847/C

//
//

//       2025-4-22-(构造)-cf847c
//思路：

//日期：   2025-4-22
//格式化： ctrl+shift+ a

typedef long long ll;

ll n;
ll k;
string s;


void solve() {

	if(n*(n-1)/2 < k ) {
		cout<<"Impossible"<<endl;
		return ;
	}
	s="";
    
    int cnt=0;
    for(int i=0;i<n;i++){
    	if(k>=n-1-i){
    		s+='(';       //当前左括号对 后续左括号 的贡献值 
    		cnt++;
    		k-=n-1-i;
		}
		else{
			s+='(';
			s+=')';
		}
	}
	while(cnt--){
		s+=')';
	}
	
	for(char ss:s){
		cout<<ss;
	}
	cout<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>k;
	solve();

	return 0;
}
/*


*/

