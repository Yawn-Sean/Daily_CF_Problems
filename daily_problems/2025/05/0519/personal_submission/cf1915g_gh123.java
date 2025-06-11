//https://codeforces.com/problemset/submission/1915/320315675
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class G1915 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
        int m=sc.nextInt();
        List<int[]>[]adj=new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i]=new ArrayList<>();
        }   
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            int w=sc.nextInt();
            adj[u].add(new int[]{v,w});
            adj[v].add(new int[]{u,w});
        }
        int[]s=new int[n];
        for (int i = 0; i < n; i++) {
            s[i]=sc.nextInt();
        }
        long[][]dis=new long[n][1001];
        boolean[][]vis=new boolean[n][1001];
        for (long[] row : dis) {
            Arrays.fill(row, (long)1e18);
        }
        dis[0][s[0]]=0;
       
        PriorityQueue<long[]>pq=new PriorityQueue<>((a,b)->Long.compare(a[0], b[0]));
        pq.add(new long[]{0l,0l,(long) s[0]});
        while (!pq.isEmpty()) {
            long[]cur=pq.poll();
            int u=(int)cur[1];
            int k=(int)cur[2];
            if(vis[u][k]||dis[u][k]==(long)1e18){
                continue;
            }
            vis[u][k]=true;
            for (int[] next : adj[u]) {
                int v=next[0];
                int w=next[1];
                int cost=Math.min(s[v], k);
                if(dis[v][cost]>dis[u][k]+1l*w*k){
                    dis[v][cost]=dis[u][k]+1l*w*k;
                    pq.add(new long[]{dis[v][cost],v,cost});
                }
            }
           
        }
             long ans=(long)1e18;
            for (int i = 1; i <=1000; i++) {
                ans=Math.min(ans, dis[n-1][i]);
            }
            System.out.println(ans);
        }
         sc.close();
    }
}
