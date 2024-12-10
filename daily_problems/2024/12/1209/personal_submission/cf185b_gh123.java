//https://codeforces.com/problemset/submission/185/295700384
import java.util.Scanner;

public class B185 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        sc.close();
        if(a>0||b>0||c>0){
            int sum=a+b+c;
            System.out.print(1.0*t*a/sum+" "+1.0*t*b/sum+" "+1.0*t*c/sum);
        }else{
            System.out.println(0+" "+0+" "+t);
        }
    }
}
