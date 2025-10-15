//https://codeforces.com/problemset/submission/741/326354122

import java.util.Scanner;

public class A741 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]per=new int[n];
        for (int i = 0; i < per.length; i++) {
            per[i]=sc.nextInt()-1;
        }
        boolean[]vis=new boolean[n];
        sc.close();
        long ans=1;
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                int x=i,c=0;
                while (!vis[x]) {
                    vis[x]=true;
                    x=per[x];
                    c++;
                }
                if(x!=i){
                    System.out.println(-1);
                    return;
                }
                if(c%2==0){
                    c=c/2;
                }
                ans=(long)ans*c/gcd(ans,c);
            }
        }
        System.out.println(ans);
    }
    public static long gcd(long a,long b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
}
