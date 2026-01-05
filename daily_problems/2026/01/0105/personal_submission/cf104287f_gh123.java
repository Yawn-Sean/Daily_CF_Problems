import java.util.Scanner;

public class F104287 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            long a=sc.nextInt(),b=sc.nextInt(),c=sc.nextInt();
            long v1=gcd(c, a*b/gcd(a, b));
            long v2=c-v1;
            System.out.println(v2);
        }   
        sc.close();
    }    
    static long gcd(long a,long b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
}
