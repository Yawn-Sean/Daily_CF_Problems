import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.List;
//超时了好几次。。。
public class cf105327d {
    public static void main(String[] args) throws IOException {
      new cf105327d().solve();
    }
    private UnionFind uf;
    private List<List<Integer>>path;
    private int[]parent;
    private int[]depth;
    private int n,m;
    public void solve() throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        StringTokenizer st;
        st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        uf=new UnionFind(n+m);
        path=new ArrayList<>(n+m);
        for (int i = 0; i < n+m; i++) {
            path.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            st=new StringTokenizer(br.readLine());
            int k=Integer.parseInt(st.nextToken());
            for (int j = 0; j < k; j++) {
                int u=Integer.parseInt(st.nextToken())-1;
                if(uf.merge(u, m+i)){
                    path.get(u).add(m+i);
                    path.get(m+i).add(u);
                }
            }
        }
        parent=new int[n+m];
        Arrays.fill(parent, -1);
        depth=new int[n+m];
        for (int i = 0; i < n+m; i++) {
            if(parent[i]==-1){
                buildtree(i,-1);
            }
        }
        int q=Integer.parseInt(br.readLine());
        StringBuilder sb=new StringBuilder();
        while (q-->0) {
            st=new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken())-1;
            int v=Integer.parseInt(st.nextToken())-1;
            if(uf.leader(u)!=uf.leader(v)){
                sb.append("-1\n");
            }else{
                List<Integer>pathu=new ArrayList<>();
                List<Integer>pathv=new ArrayList<>();
                int curu=u;
                int curv=v;
                while (true) {
                    if(curu!=-1){
                        pathu.add(curu);
                        if(pathv.contains(curu)){
                            while (pathv.get(pathv.size()-1)!=curu) {
                                pathv.remove(pathv.size()-1);
                            }
                            break;
                        }
                        curu=parent[curu];
                    }
                    if(curv!=-1){
                        pathv.add(curv);
                        if(pathu.contains(curv)){
                            while (pathu.get(pathu.size()-1)!=curv) {
                                pathu.remove(pathu.size()-1);
                            }
                            break;
                        }
                        curv=parent[curv];
                    }
                    if(pathu.get(pathu.size()-1).equals(pathv.get(pathv.size()-1))){
                        break;
                    }
                }
                Collections.reverse(pathv);
                pathu.addAll(pathv.subList(1, pathv.size()));
                int pathsize=pathu.size()/2+1;
                sb.append(pathsize).append("\n");
                StringBuilder pathline=new StringBuilder();
                for (int i = 0; i < pathu.size(); i++) {
                    int x=pathu.get(i);
                    pathline.append(x<m?x+1:x-m+1);
                    if(i<path.size()-1){
                        pathline.append(" ");
                    }
                }
                pathline.append("\n");
                sb.append(pathline);

            }
        }
        out.print(sb.toString());
        out.close();
        br.close();
    }
    private void buildtree(int u,int p){
        for (int v : path.get(u)) {
            if(v!=p){
                parent[v]=u;
                depth[v]=depth[u]+1;
                buildtree(v, u);
            }
        }
    }
    static class UnionFind {
        private final int[]parent;
        private final int[]rank;
        public UnionFind(int n){
           this.parent=new int[n];
           this.rank=new int[n];
           for (int i = 0; i < n; i++) {
            parent[i]=i;
            rank[i]=0;
           }
        }
        public int leader(int x){
            if(parent[x]!=x){
                parent[x]=leader(parent[x]);
            }
            return parent[x];
        }
        boolean merge(int x,int y){
            int rootx=leader(x);
            int rooty=leader(y);
            if(rootx!=rooty){
                if(rank[rootx]<rank[rooty]){
                    parent[rootx]=rooty;
                }else if(rank[rootx]>rank[rooty]){
                    parent[rooty]=rootx;
                }else{
                    parent[rooty]=rootx;
                    rank[rootx]++;
                }
                return true;
            }
            return false;
        }
        
    }
}
