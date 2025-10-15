//https://codeforces.com/problemset/submission/1062/289344315
import java.util.Arrays;
import java.util.Scanner;
//前缀和
public class C1062 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int q=sc.nextInt();
        int mod=(int)1e9+7;
        String s=sc.next();
        int[]pre=new int[n+1];
        int[]ans=new int[n+1];
        Arrays.fill(ans, 1);
        for (int i = 0; i < n; i++) {
            pre[i+1]=pre[i]+(s.charAt(i)-'0');
            ans[i+1]=ans[i]*2%mod;
        }
        while (q-->0) {
            int l=sc.nextInt()-1;
            int r=sc.nextInt();
            int res=ans[r-l]-ans[r-l-(pre[r]-pre[l])];
            res=res<0?res+mod:res;
            System.out.println(res);
        }
        sc.close();
    }
}
