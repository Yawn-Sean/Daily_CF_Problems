https://codeforces.com/problemset/submission/1025/261266895
import java.util.Scanner;

public class C1025 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        int n=s.length();
        s=s+s;
        int cnt=1;
        int max=0;
        for (int i = 1; i < 2*n; i++) {
            if(s.charAt(i)!=s.charAt(i-1)){
                cnt++;
            }else{
                cnt=1;
            }
            max=Math.max(max, cnt);
        }
        System.out.println(Math.min(max, n));
        sc.close();
    }
}
