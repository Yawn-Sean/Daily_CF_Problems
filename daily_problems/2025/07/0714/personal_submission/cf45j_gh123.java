//https://codeforces.com/problemset/submission/45/328870931
import java.util.Scanner;

public class J45 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        if(n+m>2&&n+m<5){
            System.out.println(-1);

        }else{
            int[][]grid=new int[n][m];
            int op=1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if((i+j)%2==1){
                        grid[i][j]=op;
                        op++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if((i+j)%2==0){
                        grid[i][j]=op;
                        op++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print(grid[i][j]+" ");
                }
                System.out.println();
            }
        }
        sc.close();
    }
}
