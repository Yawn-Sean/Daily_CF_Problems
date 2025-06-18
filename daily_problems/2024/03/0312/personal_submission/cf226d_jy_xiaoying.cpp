#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/226/D

//   通过局部最优 判断是否继续 进行优化 从而达到全局最优     贪心

//日期： 2024-3-12
//格式化： ctrl+shift+ a

const int MAX=1e3+10;
int n,m;
int g[MAX][MAX];
int sum_x[MAX],sum_y[MAX];

int x[MAX],y[MAX];

bool min_x(){
	for(int i=1;i<=n;i++){
		if(sum_x[i]<0) return 1;
	}
	return 0;
}

bool min_y(){
	for(int j=1;j<=m;j++){
		if(sum_y[j]<0) return 1;
	}
	return 0;
}

void f(){
	for(int i=0;i<MAX;i++) x[i]=y[i]=sum_x[i]=sum_y[i]=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum_x[i]+=g[i][j];
			sum_y[j]+=g[i][j];
		}
	}
	
	while(min_x() || min_y()){
		
		for(int i=1;i<=n;i++){
			if(sum_x[i]>=0) continue;
			
			sum_x[i]*=-1;
			x[i]^=1;
			for(int j=1;j<=m;j++){
				sum_y[j]-=2*g[i][j];
				g[i][j]*=-1;
			}
		}
		
		for(int j=1;j<=m;j++){
			if(sum_y[j]>=0) continue;
			
			sum_y[j]*=-1;
			y[j]^=1;
			for(int i=1;i<=n;i++){
				sum_x[i]-=2*g[i][j];
				g[i][j]*=-1;
			}
		}
		
	}
	
	int tmp=0;
	for(int i=1;i<=n;i++) tmp+=x[i];
	cout<<tmp<<" ";
	for(int i=1;i<=n;i++) {
		if(x[i]) cout<<i<<" ";
	}
	cout<<endl;
	
	tmp=0;
	for(int j=1;j<=m;j++) tmp+=y[j];
	cout<<tmp<<" ";
	for(int j=1;j<=m;j++) {
		if(y[j]) cout<<j<<" ";
	}
	cout<<endl;
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>g[i][j];
		}
	}
	
	f();

	return 0;
}
/*



*/

