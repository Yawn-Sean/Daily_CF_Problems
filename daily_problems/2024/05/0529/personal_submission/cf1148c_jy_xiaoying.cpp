//链接：https://codeforces.com/problemset/problem/1148/C

#include<bits/stdc++.h>
using namespace std;

const int MAX=3e5+10;
int g[MAX];
int id[MAX];                //数字i在那个下标 （哈希表） 
int n;

typedef vector<int> vv;
vector<vv> ans(MAX<<2);
int len;

void swp(int i,int j){               //数组【i，j】位置交换 
    int u=g[i],v=g[j];
	id[u]=j;
	id[v]=i;
    ans[len++]=vv{i,j};
	swap(g[i],g[j]);
}

void f(){
	len=0;
	for(int i=n;i>=1;i--){
		if(g[i]==i) continue;
		if(abs(i-id[i])>=n/2){    // t  ...  i
			swp(i,id[i]);
		}
		else{
			int j=id[i];                       //j一定位于 i左侧 
			if(i>n/2 && j<=n/2){               //[...j...mid...i...]
				swp(j,n);
				swp(n,1);
				swp(1,i);
				swp(j,n);
			}
			else if(i<=n/2 && j<n/2){             // [...j ... i...mid......]
				swp(j,n);
				swp(i,n);
				swp(j,n);
			}
			else{                              //[...mid...j...i...]
				swp(1,j);
				swp(1,i);
			}
		}
	}
	
	cout<<len<<"\n";
	for(int i=0;i<len;i++){
		cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
	}
	
//	cout<<"--------------------"<<endl;
//	cout<<"--------------------"<<endl;
//	cout<<"--------------------"<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<g[i]<<" ";
//	}
//	cout<<endl;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i];
		id[g[i]]=i;
	}
	
	f();
	return 0;
} 

/*
10
7 2 9 6 5 8 1 3 10 4

50
2 28 9 34 32 5 44 36 6 7 3 40 11 50 15 17 29 26 46 21 49 14 47 35 13 33 4 42 12 19 25 
30 23 27 8 38 18 39 1 24 48 37 10 31 16 20 41 43 22 45

*/
