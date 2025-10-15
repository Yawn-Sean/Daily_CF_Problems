//https://codeforces.com/problemset/submission/77/297998817
import java.util.Scanner;

public class B77 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            if(b==0){
                System.out.println(1);
            }else if(a==0){
                System.out.println(0.5);
            }else if(a<4*b){
                System.out.println(0.5+1.0*a/16/b);
            }else{
                System.out.println(1-1.0*b/a);
            }
        }
        sc.close();
    }
}
