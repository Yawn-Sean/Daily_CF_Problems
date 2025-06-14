//https://codeforces.com/problemset/submission/1006/324337215
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
public class E1006 {
    static List<Integer>g[];
    static boolean[]vis;
    static int[]size;
    static List<Integer>list;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int q=sc.nextInt();
        g=new List[n+1];
        for (int i = 0; i <=n; i++) {
            g[i]=new ArrayList<>();
        }
        list=new ArrayList<>();
        vis=new boolean[n+1];
        size=new int[n+1];
        for (int i = 2; i <=n; i++) {
            int u=sc.nextInt();
            g[u].add(i);
            g[i].add(u);
        }
       
        dfs(1);
        int[]ans=new int[n+1];
        for (int i = 0; i < n; i++) {
            ans[list.get(i)]=i;
        }
        while (q-->0) {
            int u=sc.nextInt();
            int v=sc.nextInt()-1;
            if(v>=size[u]){
                System.out.println(-1);
            }else{
                System.out.println(list.get(ans[u]+v));
            }
        }
         sc.close();
    }
    static void dfs(int v){
        size[v]=1;
        vis[v]=true;
        list.add(v);
        for (int next : g[v]) {
            if(!vis[next]){
                dfs(next);
                size[v]+=size[next];
            }
        }
    }
}
