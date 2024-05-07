//链接：https://codeforces.com/problemset/problem/989/C

#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;
const int MAX=50;
char g[MAX][MAX];

void bulid(){
	for(int i=0;i<25;i++){                  //AACC
		for(int j=0;j<25;j++)               //BBDD
		g[i][j]='A';
	}
	for(int i=25;i<50;i++){
		for(int j=0;j<25;j++)
		g[i][j]='B';
	}
	for(int i=0;i<25;i++){
		for(int j=25;j<50;j++)
		g[i][j]='C';
	}
	for(int i=25;i<50;i++){
		for(int j=25;j<50;j++)
		g[i][j]='D';
	}
}

void f(){   //A里+B   B里+C   C里+D  D里+A 
    int cnt=0;
	for(int i=1;i<25 && cnt<b-1;i+=2){
		for(int j=1;j<25 && cnt<b-1;j+=2){
			g[i][j]='B';
			cnt++;
		}
	}
	
	cnt=0;   //B里+C
	for(int i=26;i<50 && cnt<c-1;i+=2){
		for(int j=1;j<25 && cnt<c-1;j+=2){
			g[i][j]='C';
			cnt++;
		}
	}
	
	cnt=0;   //C里+D
	for(int i=1;i<25 && cnt<d-1;i+=2){
		for(int j=26;j<50 && cnt<d-1;j+=2){
			g[i][j]='D';
			cnt++;
		}
	}
	
	cnt=0;   //D里+A
	for(int i=26;i<50 && cnt<a-1;i+=2){
		for(int j=26;j<50 && cnt<a-1;j+=2){
			g[i][j]='A';
			cnt++;
		}
	}
	
	cout<<50<<" "<<50<<endl;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			cout<<g[i][j];
		}
		cout<<endl;
	}
}

int main(){
	cin>>a>>b>>c>>d;
	bulid();
	f();
	
	return 0;
} 
