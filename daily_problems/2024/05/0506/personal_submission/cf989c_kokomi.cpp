#include<bits/stdc++.h>
using namespace std;
//构造题
//连通块数不超过100，先构造四个大块
//然后在大块中插空放小块
char ans[60][60];
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<"40 50"<<endl;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=50;j++){
			ans[i][j]='A';
		}
	}
	for(int i=11;i<=20;i++){
		for(int j=1;j<=50;j++){
			ans[i][j]='B';
		}
	}
	for(int i=21;i<=30;i++){
		for(int j=1;j<=50;j++){
			ans[i][j]='C';
		}
	}
	for(int i=31;i<=40;i++){
		for(int j=1;j<=50;j++){
			ans[i][j]='D';
		}
	}
	a--,b--,c--,d--;
	int i=1,j=1;
	while(c--){
		if(j>50) i+=2,j=1;
		ans[i][j]='C';
		j+=2;
	}
	i=11,j=1;
	while(d--){
		if(j>50) i+=2,j=1;
		ans[i][j]='D';
		j+=2;
	}
	i=21,j=1;
	while(a--){
		if(j>50) i+=2,j=1;
		ans[i][j]='A';
		j+=2;		
	}
	i=31,j=1;
	while(b--){
		if(j>50) i+=2,j=1;
		ans[i][j]='B';
		j+=2;		
	}	
	for(int i=1;i<=40;i++){
		for(int j=1;j<=50;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
}