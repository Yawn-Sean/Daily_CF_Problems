//https://codeforces.com/problemset/submission/813/315790203
//用经常用的scanner就超时，换了这个bufferedReader就瞬间过了。。。
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class C813 {
    static ArrayList<Integer>[]g;
    static long[]dic_a,dic_b;
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int a=0;
        int b=Integer.parseInt(st.nextToken())-1;
        if(b==0){
            System.out.println(2);
            return;
        }
       
        dic_a=new long[n];
        dic_b=new long[n];
      Arrays.fill(dic_a, Long.MAX_VALUE);
      Arrays.fill(dic_b, Long.MAX_VALUE);
      g=new ArrayList[n];
      for (int i = 0; i < n; i++) {
        g[i]=new ArrayList<>();
      }
      for (int i = 0; i < n-1; i++) {
        st=new StringTokenizer(br.readLine());
        int u=Integer.parseInt(st.nextToken())-1;
        int v=Integer.parseInt(st.nextToken())-1;
        g[u].add(v);
        g[v].add(u);
      }
      bfs(a, dic_a);
      bfs(b, dic_b);
      long max=0;
      for (int i = 0; i < n; i++) {
        if(dic_a[i]>dic_b[i]){
            max=Math.max(max, dic_a[i]);
        }
      }
      System.out.println(max*2);
    }
    static void bfs(int x,long []d){
        Queue<Integer>que=new LinkedList<>();
        que.add(x);
        d[x]=0;
        while (!que.isEmpty()) {
            int cur=que.poll();
            for (int next : g[cur]) {
                if(d[next]==Long.MAX_VALUE){
                    d[next]=d[cur]+1;
                    que.add(next);
                }
            }
        }
    }
}
