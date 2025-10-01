import java.util.ArrayList;
import java.util.Arrays;

import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class K105833 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
        List<int[]>[]path=new ArrayList[n];
        int[]pa=new int[n];
        for (int i = 0; i < pa.length; i++) {
            pa[i]=i;
        }
        for (int i = 0; i < n; i++) {
            path[i]=new ArrayList<>();
        }
        int[][]edges=new int[m][3];
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            int w=sc.nextInt();
            edges[i][0]=u;
            edges[i][1]=v;
            edges[i][2]=w;
            path[u].add(new int[]{v,w});
            path[v].add(new int[]{u,w});
            union(u, v, pa);
        }
        sc.close();
        long ans=0;
        // List<Integer>list=new ArrayList<>();
        PriorityQueue<Integer>tem=new PriorityQueue<>();
        for (int i = 0; i < edges.length; i++) {
            int u=edges[i][0];
            if(find(0, pa)==find(u, pa)){
                // list.add(edges[i][2]);
                tem.add(edges[i][2]);
            }
        }
        // Collections.sort(list);
        int cnt=0;
        while (!tem.isEmpty()&&cnt<k) {
                ans+=tem.poll();
            cnt++;
        }
        // for (int i = 0; i < list.size(); i++) {
        //     if(i<k){
        //         ans+=list.get(i);
        //     }
        // }
        long[]dist=new long[n];
        Arrays.fill(dist, (long)1e15);
        dist[0]=0;
        PriorityQueue<long[]>pq=new PriorityQueue<>((a,b)->Long.compare(a[0], b[0]));
        pq.add(new long[]{0l,0l});
        while (!pq.isEmpty()) {
            long[]cur=pq.poll();
            long d=cur[0];
            int u=(int)cur[1];
                if(dist[u]<d)continue;
                for (int[] next : path[u]) {
                    int v=next[0];
                    int w=next[1];
                    if(dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                        pq.add(new long[]{dist[v],v});
                    }
                }
            
        }
        ans=Math.min(ans, dist[n-1]);
        System.out.println(ans);

    }
    static int find(int x,int[]pa){
        if(x==pa[x]){
            return x;
        }
        return pa[x]=find(pa[x], pa);
    }
    static void union(int x,int y,int[]pa){
        int px=find(x, pa);
        int py=find(y, pa);
        if(px>py){
            pa[px]=py;
        }else if(px<py){
            pa[py]=px;
        }else{
            return;
        }
    }
}
