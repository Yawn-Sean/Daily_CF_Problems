/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct HLPP {
    /*
     * set ANS_TYPE to int or long long
     * nodes numbered by 1, 2, ..., n
     */
    typedef long long ANS_TYPE; // or int
    struct Edge {
        int to;
        ANS_TYPE c;
        int rev;
        Edge(int to, ANS_TYPE c, int rev): to(to), c(c), rev(rev) {}
    };

    int n, m, s, t;
    int maxh, maxgaph, workcnt;
    std::vector<std::vector<Edge>> vec; // graph
    std::vector<ANS_TYPE> ov; // overflow of nodes
    std::vector<int> h;  // height of nodes
    std::vector<int> cur; // current arc
    std::vector<int> ovList, ovNxt;
    std::vector<int> gap, gapPrv, gapNxt;

    // n: nodes, m: edges, s: source node, t: sink node
    HLPP(int n, int m, int s, int t): n(n), m(m), s(s), t(t), maxh(0), maxgaph(0), workcnt(0),
                                      vec(n+1), ov(n+1), h(n+1), cur(n+1),
                                      ovList((n+1), -1), ovNxt(n+1, -1),
                                      gap((n+1), -1), gapPrv(n+1, -1), gapNxt(n+1, -1) {}

    void addEdge(int u, int v, ANS_TYPE c) {
        vec[u].push_back(Edge(v, c, vec[v].size()));
        vec[v].push_back(Edge(u, 0, vec[u].size()-1));
    }

    ANS_TYPE getMaxFlow() {
        globalRelabel();
        for(auto &e: vec[s]) if(e.c) { pushFlow(s, e, e.c);  maxh = std::max(maxh, h[e.to]); }
        for(; maxh >= 0; --maxh) {
            while(~ovList[maxh]) {
                int x = ovList[maxh];
                ovList[maxh] = ovNxt[x];
                discharge(x);
                if(workcnt > (n<<2))  globalRelabel();
            }
        }
        return ov[t];
    }
private:
    void discharge(int x) {
        int nh = n, sz = vec[x].size();
        for(int i = cur[x]; i < sz; ++i) {
            auto &e = vec[x][i];
            if(e.c > 0) {
                if(h[x] == h[e.to]+1) {
                    pushFlow(x, e, std::min(ov[x], e.c));
                    if(ov[x] == 0) { cur[x] = i;  return ; }
                } else nh = std::min(nh, h[e.to]+1);
            }
        }
        for(int i = 0; i < cur[x]; ++i) {
            auto &e = vec[x][i];
            if(e.c > 0) { nh = std::min(nh, h[e.to]+1); }
        }
        cur[x] = 0;
        ++workcnt;
        if(~gapNxt[gap[h[x]]])  setHeight(x, nh);
        else {
            int oldh = h[x];
            for(int i = oldh; i <= maxgaph; ++i) {
                for(int j = gap[i]; ~j; j = gapNxt[j])  h[j] = n;
                gap[i] = -1;
            }
            maxgaph = oldh-1;
        }
    }

    void globalRelabel() {
        workcnt = maxh = maxgaph = 0;
        std::fill(h.begin(), h.end(), n);  h[t] = 0;
        std::fill(gapPrv.begin(), gapPrv.end(), -1);
        std::fill(gapNxt.begin(), gapNxt.end(), -1);
        std::fill(gap.begin(), gap.end(), -1);
        std::fill(ovList.begin(), ovList.end(), -1);
        std::fill(ovNxt.begin(), ovNxt.end(), -1);
        std::fill(cur.begin(), cur.end(), 0);
        std::queue<int> que;  que.push(t);
        int x;
        while(!que.empty()) {
            x = que.front();  que.pop();
            for(auto &e: vec[x]) {
                if(h[e.to] == n && e.to != s && vec[e.to][e.rev].c > 0) {
                    setHeight(e.to, h[x]+1);
                    que.push(e.to);
                }
            }
        }
    }

    void setHeight(int x, int newh) {
        if(~gapPrv[x]) {
            if(gapPrv[x] == x) {
                gapPrv[gapNxt[x]] = gapNxt[x];
                gap[h[x]] = gapNxt[x];
            } else {
                gapNxt[gapPrv[x]] = gapNxt[x];
                if(~gapNxt[x])  gapPrv[gapNxt[x]] = gapPrv[x];
            }
        }
        if((h[x] = newh) >= n)  return ; // ignore the case of h >= n
        maxgaph = std::max(maxgaph, h[x]);
        if(ov[x] > 0) { maxh = std::max(maxh, h[x]);  ovNxt[x] = ovList[h[x]];  ovList[h[x]] = x; }
        if(~(gapNxt[x] = gap[h[x]]))  gapPrv[gapNxt[x]] = x;
        gap[h[x]] = gapPrv[x] = x;
    }

    void pushFlow(int from, Edge &e, ANS_TYPE flow) {
        if(!ov[e.to] && e.to != t) {
            ovNxt[e.to] = ovList[h[e.to]];
            ovList[h[e.to]] = e.to;
        }
        e.c -= flow;
        vec[e.to][e.rev].c += flow;
        ov[from] -= flow;
        ov[e.to] += flow;
    }
};


void solve(){
    std::map<std::string,int> q={
        {"S",1},{"M",2},{"L",3},{"XL",4},
        {"XXL",5},{"XXXL",6}
    };
    std::map<int,std::string> p={
        {1,"S"},{2,"M"},{3,"L"},{4,"XL"},
        {5,"XXL"},{6,"XXXL"}
    };
    std::vector<int> a(7);
    for(int i=1;i<=6;i++) std::cin>>a[i];
    int n;
    std::cin>>n;

    int s=n+10,t=n+11;
    HLPP flow(n+20,0,s,t);

    for(int i=1;i<=n;i++){
        std::string s;
        std::cin>>s;
        if(s.find(',')!=-1){
            std::string l="",r="";
            for(auto x:s){
                if(x==','){
                    l=r;
                    r.clear();
                }else r+=x;
            }
            flow.addEdge(i,n+q[l],1);
            flow.addEdge(i,n+q[r],1);
        }else flow.addEdge(i,n+q[s],1);
    }
    for(int i=1;i<=n;i++) flow.addEdge(s,i,1);
    for(int i=1;i<=6;i++) flow.addEdge(n+i,t,a[i]);
    auto res=flow.getMaxFlow();
    if(res==n){
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++){
            for(auto t:flow.vec[i]){
                if(!t.c) std::cout<<p[t.to-n]<<"\n";
            }
        }
    }else std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
