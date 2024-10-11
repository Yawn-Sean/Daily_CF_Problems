//https://codeforces.com/problemset/submission/798/272239699
import java.util.Scanner;

public class C798 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]a=new long[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
        }
        long g=gcd(a[0], a[1]);
        for (int i = 2; i < a.length; i++) {
            g=gcd(g, a[i]);
        }
        if(g>1){
            System.out.println("YES");
            System.out.println(0);
        }else{
            long cnt=0;
            for (int i = 0; i < n-1; i++) {
                while ((a[i]&1)==1) {
                    a=change(i, a);
                    cnt++;
                }
            }
            while (a[n-1]%2!=0) {
                a=change(n-2, a);
                cnt++;
            }
            System.out.println("YES");
            System.out.println(cnt);
        }
        sc.close();
    }
    static long[]change(int k,long[]a){
        long tem1=a[k];
        long tem2=a[k+1];
        a[k]=tem1-tem2;
        a[k+1]=tem1+tem2;
        return a;
    }
    static long gcd(long a, long b){
        return b==0?a:gcd(b, a%b);
    }
}
