//https://codeforces.com/problemset/submission/689/319004198
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;
//bfs会，但是没想到看了题解会1600的题。。
public class B689 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt()-1;
        }   
        sc.close();
        int[]dis=new int[n];
        Arrays.fill(dis, -1);
        dis[0]=0;
        Queue<Integer>que=new ArrayDeque<>();
        que.add(0);
        while (!que.isEmpty()) {
            int cur=que.poll();
            if(cur>0&&dis[cur-1]==-1){
                dis[cur-1]=dis[cur]+1;
                que.add(cur-1);
            }
            if(cur+1<n&&dis[cur+1]==-1){
                dis[cur+1]=dis[cur]+1;
                que.add(cur+1);
            }
            if(dis[a[cur]]==-1){
                dis[a[cur]]=dis[cur]+1;
                que.add(a[cur]);
            }
        }
        for (int i = 0; i < dis.length; i++) {
            System.out.print(dis[i]+" ");
        }
        System.out.println();
    }
}
