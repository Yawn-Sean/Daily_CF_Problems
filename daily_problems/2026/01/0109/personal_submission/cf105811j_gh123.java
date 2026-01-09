import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.PriorityQueue;
public class J105811 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        List<int[]>[]path=new ArrayList[n];
        List<int[]>[]rev=new ArrayList[n];
        for (int i = 0; i < n; i++) {
            path[i]=new ArrayList<>();
            rev[i]=new ArrayList<>();
        }   
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt(),v=sc.nextInt(),w=sc.nextInt();
            u--;
            v--;
            path[u].add(new int[]{v,w});
            rev[v].add(new int[]{u,w});
        }
        sc.close();
        int inf=(int)2e9;
        int[]d1=shortest(path,n,inf);
        int[]d2=shortest(rev,n,inf);
        for (int i = 0; i < n; i++) {
            if(d2[i]>d1[i]){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
    private static int[]shortest(List<int[]>[]graph,int n,int inf){
        int[]dist=new int[n];
        Arrays.fill(dist, inf);
        dist[0]=0;
        PriorityQueue<int[]>pq=new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.add(new int[]{0,0});
        while (!pq.isEmpty()) {
            int[]cur=pq.poll();
            int d=cur[0];
            int u=cur[1];
            if(dist[u]<d){
                continue;
            }
            for (int[] next : graph[u]) {
                int v=next[0];
                int w=next[1];
                int nw=Math.max(d, w);
                if(nw<dist[v]){
                    dist[v]=nw;
                    pq.add(new int[]{nw,v});
                }
            }
        }
        return dist;
    }
}
