// LUOGU_RID: 158222583
#include<bits/stdc++.h>
using namespace std;
int n=50,m=50;
int a[55][55];
 
void solve(){
	int x,b,c,d;cin>>x>>b>>c>>d;
	for(int i=1;i<=25;i++){
		for(int j=1;j<=25;j++)
			a[i][j]=1;
	}
	for(int i=1;i<=25;i++){
		for(int j=26;j<=50;j++)
			a[i][j]=2;
	}
	for(int i=26;i<=50;i++){
		for(int j=1;j<=25;j++){
			a[i][j]=3;
		}
	}
	for(int i=26;i<=50;i++){
		for(int j=26;j<=50;j++){
			a[i][j]=4;
		}
	}
	x--,b--,c--,d--;
	
		int q=1,f=0;
		
		for(int i=2;i<=23;i+=2){
			//q^=1;
			for(int j=q;j<=23;j+=2){
				
				if(b<=0){
					f=1;
					break;
				}
				b--;
				a[i][j]=2;
			}
			if(f)break;
		}
 
	q=1,f=0;
		
		for(int i=2;i<=23;i+=2){
			//q^=1;
			for(int j=26+q;j<=49;j+=2){
				
				if(c<=0){
					f=1;
					break;
				}
				c--;
				a[i][j]=3;
			}
			if(f)break;
		}
	
	q=1,f=0;
		
		for(int i=27;i<=49;i+=2){
			//q^=1;
			for(int j=q;j<=23;j+=2){
			
				if(d<=0){
					f=1;
					break;
				}
				a[i][j]=4;
				d--;
				
			}
			if(f)break;
		}
		
	q=1,f=0;
		
		for(int i=27;i<=49;i+=2){
			//q^=1;
			for(int j=26+q;j<=49;j+=2){
				
				if(x<=0){
					f=1;
					break;
				}
				x--;
				a[i][j]=1;
			}
			if(f)break;
		}
	
	cout<<n<<" "<<m<<"\n"; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1){
				cout<<"A";
			}
			if(a[i][j]==2){
				cout<<"B";
			}
			if(a[i][j]==3){
				cout<<"C";
			}
			if(a[i][j]==4){
				cout<<"D";
			}
		}
		cout<<"\n";
	}
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
