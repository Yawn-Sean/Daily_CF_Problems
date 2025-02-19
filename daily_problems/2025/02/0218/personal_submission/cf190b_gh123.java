//https://codeforces.com/problemset/submission/190/306622268
import java.util.Scanner;

public class B190 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x1=sc.nextInt();
        int y1=sc.nextInt();
        int r1=sc.nextInt();
        int x2=sc.nextInt();
        int y2=sc.nextInt();
        int r2=sc.nextInt();
        sc.close();
        if((r2-r1)*(r2-r1)>(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)){
            System.out.println((Math.abs(r2-r1)-Math.hypot(x2-x1, y2-y1))/2);
        }else if((r1+r2)*(r1+r2)<(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)){
            System.out.println((Math.hypot(x2-x1, y2-y1)-r1-r2)/2);
        }else{
            System.out.println(0);
        }
    }
}
