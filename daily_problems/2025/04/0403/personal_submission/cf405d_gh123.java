//https://codeforces.com/problemset/submission/405/313679260
import java.util.Scanner;

public class D405 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int s=(int)1e6;
        boolean[]vis=new boolean[s+1];
        int n=sc.nextInt();
        for (int i = 0; i < n; i++) {
            int tem=sc.nextInt();
            vis[tem]=true;
        }
        sc.close();
        System.out.println(n);
        StringBuilder sb=new StringBuilder();
        for (int i = 1; i <=s; i++) {
            if(!vis[i]&&vis[s+1-i]){
                n--;
                vis[i]=true;
                sb.append(i);
                sb.append(" ");
            }
        }
        for (int i = 1; i <=s; i++) {
            if(!vis[i]&&!vis[s+1-i]&&n>=1){
                n-=2;
                vis[i]=true;
                vis[s+1-i]=true;
                sb.append(i);
                sb.append(" ");
                sb.append(s+1-i);
                sb.append(" ");
                // System.out.print(i+" ");
                // System.out.print(s+1-i+" ");
            }
        }
        System.out.println(sb.toString());
    }
}
