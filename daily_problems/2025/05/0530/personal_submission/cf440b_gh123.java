//https://codeforces.com/problemset/submission/440/321989084
import java.util.Scanner;
//今天的题挺友好的。
public class B440 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        long sum=0;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            sum+=a[i];
        }   
        long val=sum/n;
        long cur=0,ans=0;
        sc.close();
        for (int x : a) {
            cur+=x-val;
            ans+=Math.abs(cur);
        }
        System.out.println(ans);
    }
}
