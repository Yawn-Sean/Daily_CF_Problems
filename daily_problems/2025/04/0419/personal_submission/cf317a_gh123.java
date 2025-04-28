//https://codeforces.com/problemset/submission/317/316170503
//这道题之前提交过，以为是每日羊蹄呢，查了下不是。。。
import java.util.Scanner;

public class A317 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long x=sc.nextLong();
        long y=sc.nextLong();
        long m=sc.nextLong();   
        sc.close();
        if(x>=m||y>=m){
            System.out.println(0);
        }else if(x<=0&&y<=0){
            System.out.println(-1);
        }else{
            long ans=0;
            if(x<=0){
                ans+=(y-x-1)/y;
                x+=ans*y;
            }
            if(y<=0){
                ans+=(x-y-1)/x;
                y+=ans*x;
            }
            while (x<m&&y<m) {
                if(x>y){
                    long tem=y;
                    y=x;
                    x=tem;
                }
                x+=y;
                ans++;
            }
            System.out.println(ans);
        }
    }
}
