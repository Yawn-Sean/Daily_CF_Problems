import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
//这题想是想不出来的，得看题解。。。
public class D105822 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
            int[]nodes=new int[k];
            for (int i = 0; i < nodes.length; i++) {
                nodes[i]=sc.nextInt();
            }
            List<Integer>[]path=new ArrayList[n+1];
            for (int i = 0; i < path.length; i++) {
                path[i]=new ArrayList<>();
            }
            while (m-->0) {
                int u=sc.nextInt(),v=sc.nextInt();
                path[u].add(v);
                path[v].add(u);
            }
            int cur=1;
            for (int x : nodes) {
                if(cur!=x){
                    path[cur].add(x);
                    path[x].add(cur);
                    cur=x;
                }
            }
            int[]dis=new int[n+1];
            Arrays.fill(dis, -1);
            dis[1]=0;
            Queue<Integer>que=new ArrayDeque<>();
            que.add(1);
            while (!que.isEmpty()) {
                int u=que.poll();
                for (int next : path[u]) {
                    if(dis[next]==-1){
                        dis[next]=dis[u]+1;
                        que.add(next);
                    }
                }
            }
            boolean flag=true;
            for (int i = 1; i < k; i++) {
                if(dis[nodes[i]]<=dis[nodes[i-1]]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                if(nodes[0]==1){
                    System.out.println(k-1);
                }else{
                    System.out.println(k);
                }
                cur=1;
                for (int x : nodes) {
                    if(cur!=x){
                        System.out.println(cur+" "+x);
                        cur=x;
                    }
                }
            }else{
                System.out.println(-1);
            }
        }
        sc.close();
    }
}
