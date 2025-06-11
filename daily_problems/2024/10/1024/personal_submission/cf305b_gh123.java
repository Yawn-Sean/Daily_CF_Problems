//https://codeforces.com/problemset/submission/305/287606671
import java.math.BigInteger;
import java.util.Scanner;

public class B305 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BigInteger p=sc.nextBigInteger();
        BigInteger q=sc.nextBigInteger();
        int n=sc.nextInt();
        BigInteger[]a=new BigInteger[90];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextBigInteger();
        }
        sc.close();
        for (int i = 0; i < n; i++) {
            p=p.subtract(q.multiply(a[i]));
            BigInteger tem=p;
            p=q;
            q=tem;
        }
        if(p.equals(BigInteger.ZERO)||q.equals(BigInteger.ZERO)){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        
    }
}
