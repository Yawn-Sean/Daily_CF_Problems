//https://codeforces.com/problemset/submission/922/284258943
//今天代码挺短的
import java.util.Scanner;

public class C922 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long k=sc.nextLong();
        for (int i = 1; i <=k; i++) {
            if(n%i!=i-1){
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
        sc.close();
    }
}
