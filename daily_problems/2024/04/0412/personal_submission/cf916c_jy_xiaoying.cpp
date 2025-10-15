#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/916/C

//      思维 - 构造 
//思路：

//日期：  2024-4-12
//格式化： ctrl+shift+ a


const int MAX=1e5+10;
typedef long long ll;
typedef vector<int> vv;

const ll inf=1000003;
int n,k;

void solve(){
	ll sum=inf;
	
	cout<<sum<<" "<<sum<<endl;
	for(int i=1;i<n-1;i++){
		cout<<i<<" "<<(i+1)<<" "<<"1"<<endl;
		sum--;
	}
	cout<<(n-1)<<" "<<n<<" "<<sum<<endl;
	
	k-=(n-1);
	int id=1;
	while(k>0){
		for(int j=id+2;j<=n;j++){
			if(k<=0) break;
			cout<<id<<" "<<j<<" "<<inf<<endl;
			k--;
		}
		id++;
		if(k<=0) break;
	}
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

