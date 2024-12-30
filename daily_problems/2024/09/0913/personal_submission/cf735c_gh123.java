//https://codeforces.com/problemset/submission/735/280932972
import java.util.Scanner;
//这次的代码好短，思维含量高。
public class C735 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        sc.close();
        long d1=2,d2=1;
        long cur=0;
        while (d1<=n) {
            d1=d1+d2;
            d2=d1-d2;
            cur++;
        }
        System.out.println(cur);
    }
    
}
