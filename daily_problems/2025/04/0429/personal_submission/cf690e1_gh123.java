https://codeforces.com/problemset/submission/690/317701279
import java.util.Scanner;

public class E690 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int r=sc.nextInt();
            int c=sc.nextInt();
            int[][]grid=new int[r][c];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    grid[i][j]=sc.nextInt();
                }
            }
            int a=0,b=0;
            for (int i = 0; i < c; i++) {
                a+=Math.abs(grid[0][i]-grid[r-1][i]);
                b+=Math.abs(grid[r/2][i]-grid[r/2-1][i]);
            }
            System.out.println(a>b?"No":"Yes");
        }  
        sc.close();
    }
}
