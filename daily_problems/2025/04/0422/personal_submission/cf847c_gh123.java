//https://codeforces.com/problemset/submission/847/316622610
import java.util.Scanner;
 
public class C847 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long k=sc.nextLong();   
        sc.close();
        if(n*(n-1)/2<k){
            System.out.println("Impossible");
        }else{
            int cnt=0;
            for (int i = 0; i < n; i++) {
                if(k>=n-1-i){
                    System.out.print("(");
                    cnt++;
                    k-=n-1-i;
                }else{
                    System.out.print("()");
                }
            }
            while (cnt-->0) {
                System.out.print(")");
            }
        }
    }
}
