//https://codeforces.com/problemset/submission/1009/286319225
import java.util.Scanner;
//这道题超出我的水平了。。。
public class C1009 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long m=sc.nextLong();
        long max=Long.MIN_VALUE;
        long min=Long.MAX_VALUE;
        for (long i = 1; i <=n; i++) {
            long t=(n*n+2*i*i+n-2*i-2*i*n)/2;
            max=Math.max(max, t);
            min=Math.min(min, t);
        }
        long ans=0;
        for (long i = 1; i <=m; i++) {
            long t=sc.nextLong();
            ans+=n*t;
            long d=sc.nextLong();
            if(d>=0){
                ans+=d*max;
            }else{
                ans+=d*min;
            }
        }
        System.out.println(String.format("%.8f", ans*1.0/n));
        sc.close();
    }
}
