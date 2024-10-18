//https://codeforces.com/problemset/submission/756/285114199
import java.util.Scanner;

import javax.crypto.spec.IvParameterSpec;

public class A756 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n+1];
        int[]b=new int[n+1];
        for (int i = 1; i <=n; i++) {
            a[i]=sc.nextInt();
        }
        int s=1;
        for (int i = 1; i <=n; i++) {
            b[i]=sc.nextInt();
            s+=b[i];
        }
        sc.close();
        s%=2;
        int lops=0;
        boolean[]vis=new boolean[n+1];
        for (int i = 1; i <=n; i++) {
            if(vis[i])continue;
            lops++;
            int next=i;
            while (!vis[next]) {
                vis[next]=true;
                next=a[next];
            }
        }
        if(lops==1){
            System.out.println(s);
        }else{
            System.out.println(s+lops);
        }
    }    
}
