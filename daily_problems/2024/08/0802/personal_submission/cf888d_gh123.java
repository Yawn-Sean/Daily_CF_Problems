//https://codeforces.com/problemset/submission/888/273956254
import java.util.Scanner;

public class D888 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        int k=sc.nextInt();
        sc.close();
        long ans=1;
        if(k>=2){
            ans+=n*(n-1)/2;
        }
        if(k>=3){
            ans+=n*(n-1)*(n-2)/3;
        }
        if(k>=4){
            ans+=3*n*(n-1)*(n-2)*(n-3)/8;
        }
        System.out.println(ans);
    }
}
