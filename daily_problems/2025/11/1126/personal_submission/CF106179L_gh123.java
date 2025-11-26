import java.util.Arrays;
import java.util.Scanner;

public class L106197 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            char[][]ans=new char[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(ans[i], '1');
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    ans[i][j]='3';
                }
            }
            for (int i = n%2; i < n; i++) {
                ans[n-1][i]++;
            }
            for (int i = 0; i < ans.length; i++) {
                System.out.println(String.valueOf(ans[i]));
            }
        }   
        sc.close();
    }
}
