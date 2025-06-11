//链接：https://codeforces.com/problemset/problem/33/B

#include<bits/stdc++.h>
using namespace std;

const int MAX=510;
char x[MAX];
char y[MAX];
int cost[MAX];

string s,t;
int n;
const int inf=INT_MAX/4;

int g[30][30];

int dai[30][30];
char bian[30][30];

void build() {
	for(int i=0; i<30; i++) {
		for(int j=0; j<30; j++) {
			g[i][j]=dai[i][j]=inf;
			bian[i][j]='?';
		}
		g[i][i]=0;
	}
	for(int i=0; i<n; i++) {
		int a=x[i]-'a';
		int b=y[i]-'a';
		g[a][b]=min(g[a][b],cost[i]);

	}
	//floyd
	for(int k=0; k<26; k++) {
		for(int j=0; j<26; j++) {
			for(int i=0; i<26; i++) {
				if( g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];

			}
		}
	}
	
	//a->k  b->k
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			for(int k=0;k<26;k++){
				if(dai[i][j]>g[i][k]+g[j][k]){
					dai[i][j]=g[i][k]+g[j][k];
					bian[i][j]=k+'a';
				}
			}
		}
	}
	return ;
}

void f() {
	if(s.size()!=t.size()) {
		cout<<-1<<"\n";
		return ;
	}
	int ans=0;
	string str="";
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]==t[i]) {
			str+=s[i];
			continue;
		}
		int a=s[i]-'a',b=t[i]-'a';
		if(dai[a][b]>=inf) {
			cout<<-1<<"\n";
			return ;
		}

		ans+=dai[a][b];
		str+=bian[a][b];

	}

	cout<<ans<<"\n"<<str<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>s>>t;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x[i]>>y[i]>>cost[i];
	}
	build();

	f();
	return 0;
}

/*

uayd
uxxd
3
a x 8
x y 13
d c 3

bbad
abxd
4
b a 7
a b 10
x a 0
d t 19

abcd
acer
6
b c 100
c b 10
c x 1
e x 3
c e 7
r d 11


wye
upt
13
z z 5
e t 8
t f 2
f e 3
p l 16
l s 6
s q 13
y o 4
o q 0
u w 5
k m 14
m i 10
w u 12
*/
