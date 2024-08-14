//https://codeforces.com/problemset/submission/578/276343077
import java.util.Scanner;

public class A578 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long x=sc.nextLong();
        long y=sc.nextLong();
        if(y>x){
            System.out.println(-1);
        }else{
            double c=x+y;
            double res=c/2;
            long k=(long)Math.floor(res/(double)y);
            System.out.println(res/k);
        }
        sc.close();
    }
}
