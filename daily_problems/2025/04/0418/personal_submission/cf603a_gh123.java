//https://codeforces.com/problemset/submission/603/316031705
import java.util.Scanner;

public class A603 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        sc.close();
        int sum=0;
        for (int i = 1; i < n; i++) {
            if(s.charAt(i)!=s.charAt(i-1)){
                sum++;
            }
        }
        System.out.println(Math.min(sum+3, n));
    }
}
