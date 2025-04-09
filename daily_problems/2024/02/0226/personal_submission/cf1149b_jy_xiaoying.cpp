#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1149/B
//日期：2024-2-26
//格式化： ctrl+shift+ a

const int MAX=260;
const int MAX_N=1e5+10;
int n,k;
char s[MAX_N];
int dp[MAX][MAX][MAX];
int pos[MAX_N][26];
int a,b,c;
string s1,s2,s3;

void build() {
	a=b=c=0;
	s1=s2=s3="";

	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			for(int k=0; k<MAX; k++) {
				dp[i][j][k]=n+1;
			}
		}
	}

	dp[0][0][0]=0;    //********************************

	vector<int> tmp(30,n+1);
	
	for(int i=0;i<26;i++) pos[n+1][i]=pos[n+2][i]=n+1; 
	
	for(int i=n; i>=0; i--) {
		tmp[s[i]-'a']=i;
		for(int j=0; j<26; j++) {
			pos[i][j]=tmp[j];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>k;
	
	for(int i=1; i<=n; i++) cin>>s[i];
	

	build();

	for(int i=0; i<k; i++) {
		char ss,tt;
		int id;
		cin>>ss;

		if(ss=='+') {
			cin>>id;
			cin>>tt;

			if(id==1) {
				a++;
				s1+=tt;
			} else if(id==2) {
				b++;
				s2+=tt;

			} else {
				c++;
				s3+=tt;
			}


			for(int p=(id==1?a:0); p<=a; p++) {
				for(int q=(id==2?b:0); q<=b; q++) {
					for(int f=(id==3?c:0); f<=c; f++) {
						int &ans=dp[p][q][f];
						ans=n+1;
						if(p && dp[p-1][q][f]+1<=n)
							ans=min(ans,pos[dp[p-1][q][f]+1][s1[p-1]-'a']);

						if(q && dp[p][q-1][f]+1<=n)
							ans=min(ans,pos[dp[p][q-1][f]+1][s2[q-1]-'a']);

						if(f && dp[p][q][f-1]+1<=n )
							ans=min(ans,pos[dp[p][q][f-1]+1][s3[f-1]-'a']);	
					}
				}
			}
		}

		else  {
			cin>>id;
			if(id==1) a--,s1.pop_back();
			else if(id==2) b--,s2.pop_back();
			else c--,s3.pop_back();
		}

		if(dp[a][b][c]<=n) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;



	}
	
   	
	
	return 0;
}
