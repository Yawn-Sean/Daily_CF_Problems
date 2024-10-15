//https://codeforces.com/problemset/submission/993/276864698
//今天没 in queue....
import java.util.Scanner;

public class A993 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a1=1000,a2=-1000,b1=1000,b2=-1000,a3=1000,a4=-1000,b3=1000,b4=-1000;
        for (int i = 0; i < 4; i++) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            a1=Math.min(a1, a);
            a2=Math.max(a2, a);
            b1=Math.min(b1, b);
            b2=Math.max(b2, b);
        }
        for (int i = 0; i < 4; i++) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            a3=Math.min(a3, a+b);
            a4=Math.max(a4, a+b);
            b3=Math.min(b3, a-b);
            b4=Math.max(b4, a-b);
        }
        sc.close();
        for (int i = a1; i <=a2; i++) {
            for (int j = b1; j <=b2; j++) {
                if(i+j>=a3&&i+j<=a4&&i-j>=b3&&i-j<=b4){
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");

    }
    
}
