//https://codeforces.com/problemset/submission/449/279735919
import java.util.Scanner;

public class A449 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long m=sc.nextLong();
        long k=sc.nextLong();
        if(m>n){
            long tem=m;
            m=n;
            n=tem;//swap
        }
        long ans=-1;
        if(k<n){
            ans=m*(n/(k+1));
            if(k<m){
                ans=Math.max(ans,n*(m/(k+1)));
            }
        }else if(k+1<m+n){
            ans=m/(k+2-n);
        }
        System.out.println(ans);
        sc.close();
    }   
}
