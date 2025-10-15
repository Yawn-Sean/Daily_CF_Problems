#include<bits/stdc++.h>
using namespace std;
char g[105][105];
char a[105][105];
int main(){
	int T, r, c, k;
	cin>>T;
	while(T--){
		cin>>r>>c>>k;
		int s=0, cnt, ecnt;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>g[i][j];
				if(g[i][j]=='R') s++;
			}
		}
		cnt=s/k; ecnt=s%k;
		int res=0, idx=48;
		for(int i=1;i<=r;i++){
			if(i%2){
				for(int j=c;j>=1;j--){
					if(g[i][j]=='R') res++;
					if(ecnt){
						if(res>cnt+1){
							ecnt--;
							res=1;
							++idx;
							if(idx=='9'+1) idx='A';
							if(idx=='Z'+1) idx='a';
							a[i][j]=idx;
						}else{
							a[i][j]=idx;
						}
					}else{
						if(res>cnt){
							res=1;
							++idx;
							if(idx=='9'+1) idx='A';
							if(idx=='Z'+1) idx='a';
							a[i][j]=idx;
						}else{
							a[i][j]=idx;
						}
					}
				}
			}else{
				for(int j=1;j<=c;j++){
					if(g[i][j]=='R') res++;
					if(ecnt){
						if(res>cnt+1){
							ecnt--;
							res=1;
							++idx;
							if(idx=='9'+1) idx='A';
							if(idx=='Z'+1) idx='a';
							a[i][j]=idx;
						}else{
							a[i][j]=idx;
						}
					}else{
						if(res>cnt){
							res=1;
							++idx;
							if(idx=='9'+1) idx='A';
							if(idx=='Z'+1) idx='a';
							a[i][j]=idx;
						}else{
							a[i][j]=idx;
						}
					}
				}
			}
		}
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
