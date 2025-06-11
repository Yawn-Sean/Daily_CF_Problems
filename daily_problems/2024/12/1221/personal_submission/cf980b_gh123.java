//https://codeforces.com/problemset/submission/980/297588019
import java.util.Arrays;
import java.util.Scanner;

public class B980 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        char[][]cs=new char[4][n];
        for (int i = 0; i < 4; i++) {
            Arrays.fill(cs[i], '.');
        }
        sc.close();
        System.out.println("YES");
        if(k%2==0){
            for (int i = 1; i <=k/2; i++) {
                cs[1][i]='#';
                cs[2][i]='#';
            }
        }else{
            int v=k/2;
            cs[1][n/2]='#';
            for (int i = 1; i <=2; i++) {
                for (int j = 1; j < n/2; j++) {
                    if(v>0){
                        v--;
                        cs[i][j]='#';
                        cs[i][n-j-1]='#';
                    }
                }
            }
        }
        for (int i = 0; i < cs.length; i++) {
            System.out.println(String.valueOf(cs[i]));
        }
    }
}
