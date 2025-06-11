//https://codeforces.com/problemset/submission/340/300343477
import java.util.Arrays;
import java.util.Scanner;

public class C340 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        Arrays.sort(a);
        long ans=0;
        sc.close();
        for (int i = 0; i < n; i++) {
            ans+=1l*(4*i-2*n+3)*a[i];
        }
        long g=gcd(ans,(long)n);
        System.out.println(ans/g+" "+n/g);
    }
    static long gcd(long a,long b){
        return b==0?a:gcd((long)b, a%b);
    }
}

