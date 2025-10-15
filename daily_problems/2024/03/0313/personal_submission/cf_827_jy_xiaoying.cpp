#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/827/A

//    并查集

//日期： 2024-3-13
//格式化： ctrl+shift+ a

const int MAX=2e6+100;
typedef long long ll;
typedef vector<int> vv;
vector<vv> g;
vector<string> ss;

int n;
int fa[MAX];
string s;
int cnt;

int E_end;
char ans[MAX];

void bulid() {
	E_end=-1;
	for(int i=0; i<MAX; i++) {
		fa[i]=i;
		ans[i]='a';
	}
}

int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void U_union(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(x>y) {
		fa[y]=x;
	}
	else {
		fa[x]=y;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    bulid();
    cin>>n;
    g=vector<vv>(n+10,vv());
    ss=vector<string>(n+10);
    
    int tmp;
    for(int i=1;i<=n;i++){
    	cin>>ss[i]>>cnt;
    	for(int j=0;j<cnt;j++){
    		cin>>tmp;
    		g[i].push_back(tmp);
		}
	}
    for(int j=1;j<=n;j++){
    	s=ss[j];
    	cnt=g[j].size();
    	int len=s.size();
    	int id;
    	
    	for(int k=0;k<cnt;k++){
    		id=g[j][k];
    		int limits=id+len;
    		E_end=max(E_end,limits);
    		
    		int i=find(id);
    		while(i<limits){
    			if(i<limits){
    				ans[i]=s[i-id];
    				U_union(i,i+1);
    				i=find(i);
				}
				else{
					break;
				}
				
			}
		}
	}
    
    for(int i=1;i<E_end;i++){
    	cout<<ans[i];
	}
	cout<<endl;

	return 0;
}
/*


*/

