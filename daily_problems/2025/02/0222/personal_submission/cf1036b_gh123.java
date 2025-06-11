//https://codeforces.com/problemset/submission/1036/307210471
import java.util.Scanner;

public class B1036 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            long n=sc.nextLong();
            long m=sc.nextLong();
            long k=sc.nextLong();
            if(k<Math.max(n, m)){
                System.out.println(-1);
            }else if((n+m)%2==1){
                System.out.println(k-1);
            }else if(n%2==k%2){
                System.out.println(k);
            }else{
                System.out.println(k-2);
            }
        }
        sc.close();
    }
}
