//链接：https://codeforces.com/problemset/problem/623/A

#include<bits/stdc++.h>
using namespace std;

const int MAX=510;
int g[MAX][MAX];

int fa[MAX];    //并查集 
int cnt[MAX];

int n,m;

void bulid(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
		  g[i][j]=0;
	}
	for(int i=0;i<=n;i++){
		g[i][i]=2;
		fa[i]=i;
		cnt[i]=1;
	}
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

bool isSame(int x,int y){
	return find(x)==find(y);
}

void unio(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	fa[x]=y;
	cnt[y]+=cnt[x];
}

int getCnt(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int tmp=find(i);
		if(tmp==i && cnt[tmp]>1) ans++;
	}
	return ans;
}

char other(char ss){
	return ss=='a'?'c':'a';
}

bool check(vector<char> &s){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]==0){
				if(!((s[i]=='a' && s[j]=='c') || (s[i]=='c' && s[j]=='a')))
				return 0;
			}
			if(g[i][j]!=0){
				if((s[i]=='a' && s[j]=='c') || (s[i]=='c' && s[j]=='a'))
				return 0;
			}
		}
	}
	return 1;
}

void f(){
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]!=0) continue;
			unio(i,j);
		}
	}
	if(getCnt()>=2){
		cout<<"No"<<"\n";
		return ;
	}
	vector<char> s(n+1,'b');
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]!=0) continue;
			if(s[i]=='b' && s[j]=='b'){
				s[i]='a';
				s[j]='c';
			}
			else if(s[i]=='b'){
				s[i]=other(s[j]);
			}
			else if(s[j]=='b')
			    s[j]=other(s[i]);
		}
	}
	if(!check(s)) {
		cout<<"No"<<"\n";
		return ;
	}
	string ans="";
	for(int i=1;i<=n;i++){
		ans+=s[i];
	}
	cout<<"Yes"<<"\n"<<ans;
}

int main(){
	
	
	cin>>n>>m;
	bulid();
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		g[x][y]=2;    //2->'b'
		g[y][x]=2;
	}
	
	f();
	return 0;
} 
