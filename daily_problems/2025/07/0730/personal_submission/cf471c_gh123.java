//https://codeforces.com/problemset/submission/471/331529672
import java.util.Scanner;
//binary_search

public class C471 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long l=1,r=(long)1e9;
        long ans=-1;
        while (l<=r) {
            long mid=(l+r)/2;
            long val=mid*(3*mid+1)/2;
            if(val<=n){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }   
        System.out.println((ans+n%3)/3);
        sc.close();
    }
}
