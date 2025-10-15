//https://codeforces.com/problemset/submission/1118/335873721
import java.util.Scanner;


public class C1118 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]cnt=new int[1001];
        for (int i = 0; i < n*n; i++) {
            cnt[sc.nextInt()]++;
        }
        sc.close();
        int x=0;
        int[][]grid=new int[n][n];
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                while (x<1001&&cnt[x]<4) {
                    x++;
                }
                if(x==1001){
                    System.out.println("NO");
                    return;
                }
                grid[i][j]=x;
                grid[n-1-i][j]=x;
                grid[i][n-1-j]=x;
                grid[n-1-i][n-1-j]=x;
                cnt[x]-=4;
            }
        }
        if(n%2==1){
            x=0;
            for (int i = 0; i < n/2; i++) {
                while (x<1001&&cnt[x]<2) {
                    x++;
                }
                if(x==1001){
                    System.out.println("NO");
                    return;
                }
                grid[i][n/2]=x;
                grid[n-1-i][n/2]=x;
                cnt[x]-=2;
            }
            for (int i = 0; i < n/2; i++) {
                while (x<1001&&cnt[x]<2) {
                    x++;
                }
                if(x==1001){
                    System.out.println("NO");
                    return;
                }
                grid[n/2][i]=x;
                grid[n/2][n-1-i]=x;
                cnt[x]-=2;
            }
            for (int i = 0; i <=1000; i++) {
                if(cnt[i]==1){
                    grid[n/2][n/2]=i;
                }
            }
        }
        System.out.println("YES");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }
    }
}
