//https://codeforces.com/problemset/submission/303/323845359
import java.util.Scanner;

public class B303 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int x=sc.nextInt();
        int y=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int gcd=gcd(a,b);  
        a/=gcd;
        b/=gcd; 
        sc.close();
       int t=Math.min(n/a, m/b);
       int v=t*a,w=t*b;
       int x0=Math.min(n-v, Math.max(x-(v+1)/2, 0));
       int y0=Math.min(m-w,Math.max(y-(w+1)/2, 0));
       System.out.println(x0+" "+y0+" "+(x0+v)+" "+(y0+w));
    }
    static int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
}
