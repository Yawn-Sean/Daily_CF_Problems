//链接：https://codeforces.com/problemset/problem/1028/C

#include<bits/stdc++.h>
using namespace std;

int n;

const int MAX=150000;

typedef vector<int> vv;

vector<vv> g(MAX);

int Xmin_left[MAX];      //  (Xmax,Xmin)     
int Xmax_left[MAX];
int Xmin_right[MAX];
int Xmax_right[MAX];

int Ymin_left[MAX];
int Ymax_left[MAX];       //  Ymin
int Ymin_right[MAX];      //  Ymax
int Ymax_right[MAX];

void xx(){
	Xmin_left[0]=g[0][2];
	Xmax_left[0]=g[0][0];
	for(int i=1;i<n;i++){
		Xmin_left[i]=min(Xmin_left[i-1],g[i][2]);
		Xmax_left[i]=max(Xmax_left[i-1],g[i][0]);
	}
	
	Xmin_right[n-1]=g[n-1][2];
	Xmax_right[n-1]=g[n-1][0];
	for(int i=n-2;i>=0;i--){
		Xmin_right[i]=min(Xmin_right[i+1],g[i][2]);
		Xmax_right[i]=max(Xmax_right[i+1],g[i][0]);
	}
}

void yy(){
	Ymin_left[0]=g[0][3];
	Ymax_left[0]=g[0][1];
	for(int i=1;i<n;i++){
		Ymin_left[i]=min(Ymin_left[i-1],g[i][3]);
		Ymax_left[i]=max(Ymax_left[i-1],g[i][1]);
	}
	
	Ymin_right[n-1]=g[n-1][3];
	Ymax_right[n-1]=g[n-1][1];
	for(int i=n-2;i>=0;i--){
		Ymin_right[i]=min(Ymin_right[i+1],g[i][3]);
		Ymax_right[i]=max(Ymax_right[i+1],g[i][1]);
	}
}

void f(){
	xx();
	yy();
	int ans_x,ans_y;
	int x_min,x_max;
	int y_min,y_max;
	for(int i=0;i<n;i++){
		if(i==0){
			x_min=Xmin_right[i+1];
			x_max=Xmax_right[i+1];
			y_min=Ymin_right[i+1];
			y_max=Ymax_right[i+1];
		}
		else if(i==n-1){
			x_min=Xmin_left[i-1];
			x_max=Xmax_left[i-1];
			y_min=Ymin_left[i-1];
			y_max=Ymax_left[i-1];
		}
		else{
			x_min=min(Xmin_left[i-1],Xmin_right[i+1]);
			x_max=max(Xmax_left[i-1],Xmax_right[i+1]);
			y_min=min(Ymin_left[i-1],Ymin_right[i+1]);
			y_max=max(Ymax_left[i-1],Ymax_right[i+1]);
		}
		if(x_max<=x_min && y_max<=y_min){
			ans_x=x_max;
			ans_y=y_max;
			break;
		}
	}
	
	printf("%d %d",ans_x,ans_y);
}

int main(){
	
	scanf("%d",&n);
	
	int x1,y1,x2,y2;
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		g[i]=vv{x1,y1,x2,y2};
	}
	
	f();
	return 0;
} 
