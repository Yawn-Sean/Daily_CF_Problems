#include<bits/stdc++.h>
using namespace std;
char g[55][55];
bool f[105][105];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>g[i]+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]=='o'){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						if(g[ii][jj]=='.'){
							f[n+ii-i][n+jj-j]=1;//1:'.'
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]=='x'){
				bool fg=1;
				for(int ii=1;ii<=2*n-1;ii++){
					for(int jj=1;jj<=2*n-1;jj++){
						if(f[ii][jj]==0){
							int ti=i+n-ii, tj=j+n-jj;
							if(ti>0&& ti<=n&& tj>0&& tj<=n&& g[ti][tj]=='o') fg=0;
						}
					}
				}
				if(fg){
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=2*n-1;j++){
			if(i==n&& j==n) cout<<'o';
			else cout<<(f[i][j] ? '.':'x');
		}
		cout<<endl;
	}
	return 0;
}
