#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1016/D

//  构造 + 思维 + 异或 
//

//日期： 2024-4-1
//格式化： ctrl+shift+ a

const int MAX=110;
typedef long long ll;

int n,m;
int ans[MAX][MAX];

int x[MAX];
int y[MAX];

void f(){
	ans[0][0]=x[0];
	for(int i=1;i<n;i++){
		ans[i][0]=x[i];
	}
	
	for(int j=1;j<m;j++){
		ans[0][0]^=y[j];
		ans[0][j]=y[j];
	}
	
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m;
    int x1=0;
    for(int i=0;i<n;i++){
    	cin>>x[i];
    	x1^=x[i];
	}
	
	int y1=0;
	for(int i=0;i<m;i++){
		cin>>y[i];
		y1^=y[i];
	}
	
	if(x1!=y1){
		cout<<"NO"<<endl;
		return 0;
	}
	f();

	return 0;
}
/*



*/

