//https://codeforces.com/problemset/submission/712/288019353
import java.util.Scanner;
 //今天代码量不多，真好
public class C712 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        int y=sc.nextInt();
        int a=y,b=y,cnt=0;
        sc.close();
        while (a<x) {
            b+=a-1;
            int tem=a;
            a=b;
            b=tem;
            cnt++;
        }
        System.out.println(cnt+2);
    }
}
