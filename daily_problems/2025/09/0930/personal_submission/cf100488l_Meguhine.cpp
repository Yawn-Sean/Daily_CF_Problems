#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
char DEBUG_BUFFER[1000];
#define debug(...) {sprintf(DEBUG_BUFFER,##__VA_ARGS__);\
cerr<<"\033[1;36m"<<DEBUG_BUFFER<<"\033[0;2m"<<"\033[0m";\
fflush(stderr);}
#define s S.c_str()
char TEST_GEN[1000],TEST_ANS[1000],TEST_OUT[1000],TEST_FC[1000];
void TEST(string S){
	sprintf(TEST_GEN,"%s_gen.exe > %s_input.txt",s,s);
	sprintf(TEST_ANS,"%s_sol.exe < %s_input.txt > %s_ans.txt",s,s,s);
	sprintf(TEST_OUT,"%s.exe < %s_input.txt > %s_out.txt",s,s,s);
	sprintf(TEST_FC,"fc %s_ans.txt %s_out.txt /n",s,s);
	while(1){
		debug("gen\n"); system(TEST_GEN);
		debug("ans\n"); system(TEST_ANS);
		debug("out\n"); system(TEST_OUT);
		if(system(TEST_FC)) break;
	}
}
#undef s
#else
#define debug(...) ;
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
int rand(int l,int r){return rng()%(r-l+1)+l;}

template<typename T>
class fhqTreap{
private:
	struct Node{
		int l,r,siz; LL rnd;
		T val; bool lazy;
		Node(){
			l=r=siz=lazy=0;
			rnd=0ll; val=T(0);
		}
		Node(int l_,int r_,int siz_,LL rnd_,T val_){
			l=l_,r=r_,siz=siz_,lazy=0;
			rnd=rnd_; val=val_;
		}
	};
	vector<Node>q;
	int root,rootX,rootY,rootZ;
	int New(T val){
		Node new_node=Node(0,0,1,rng(),val);
		q.push_back(new_node);
		return q.size()-1;
	}
	void update(int id){
		q[id].siz=q[q[id].l].siz+q[q[id].r].siz+1;
	}
	void spread(int id){
		if(!id) return;
		if(q[id].lazy){
			q[q[id].l].lazy^=1;
			q[q[id].r].lazy^=1;
			swap(q[id].l,q[id].r);
			q[id].lazy=0;
		}
	}
	void split(int id,int key,int& x,int& y){
		if(id==0){
			x=y=0;
			return;
		}
		spread(id);
		if(q[q[id].l].siz+1<=key){
			x=id;
			split(q[id].r,key-q[q[id].l].siz-1,q[id].r,y);
		}
		else{
			y=id;
			split(q[id].l,key,x,q[id].l);
		}
		update(id);
	}
	int merge(int l,int r){
		if(l==0 || r==0) return l+r;
		if(q[l].rnd<=q[r].rnd){
			spread(r);
			q[r].l=merge(l,q[r].l);
			update(r);
			return r;
		}
		else{
			spread(l);
			q[l].r=merge(q[l].r,r);
			update(l);
			return l;
		}
	}
	void print(vector<T>&a,int u){
		if(!u) return;
		spread(u);
		print(a,q[u].l);
		a.push_back(q[u].val);
		print(a,q[u].r);
	}
public:
	fhqTreap(){
		init();
	}
	void init(){
		root=0; q.clear();
		Node empty_node=Node();
		q.push_back(empty_node);
	}
	void insert(T x){
		root=merge(root,New(x));
	}
	void reverse(int l,int r){
		split(root,l-1,rootX,rootZ);
		split(rootZ,r-l+1,rootY,rootZ);
		q[rootY].lazy^=1;
		root=merge(merge(rootX,rootY),rootZ);
	}
	T get(int rank){
		int id=root;
		while(1){
			spread(id);
			if(q[q[id].l].siz>=rank) id=q[id].l;
			else if(q[q[id].l].siz+1==rank) return q[id].val;
			else{
				rank-=(q[q[id].l].siz+1);
				id=q[id].r;
			}
		}
	}
	void to_ary(vector<T>&a){
		a.clear();
		print(a,root);
	}
};

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,l,r;
	cin>>n>>l>>r;
	string s; cin>>s;
	fhqTreap<char>a;
	for(auto& c:s) a.insert(c);
	string ans;
	int Q; cin>>Q;
	for(char op,x,y;Q--;){
		cin>>op;
		if(op=='S'){
			cin>>x>>y;
			int& idx=(x=='L'?l:r);
			if(y=='L') --idx;
			else ++idx;
		}
		else if(op=='Q'){
			cin>>x;
			if(x=='L'){
				ans.push_back(a.get(l));
			}
			else{
				ans.push_back(a.get(r));
			}
		}
		else{ // 'R'
			a.reverse(l,r);
		}
#ifdef LOCAL
		vector<char>ck;
		a.to_ary(ck);
		debug("\tl=%d r=%d\n",l,r);
		debug("\t");
		for(auto& c:ck)  debug("%c",c);
		debug("\n");
#endif
	}
	cout<<ans;
	return 0;
}
