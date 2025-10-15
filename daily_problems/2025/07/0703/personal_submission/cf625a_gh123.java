//https://codeforces.com/problemset/submission/625/327165913
import java.util.Scanner;

public class A625 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong(),a=sc.nextLong(),b=sc.nextLong(),c=sc.nextLong();
        long ans=0;
        if(n>=b&&b-c<=a){
            ans=(n-b)/(b-c)+1;
            n-=ans*(b-c);
        }
        ans+=n/a;
        sc.close();//
        System.out.println(ans);
    }
}
