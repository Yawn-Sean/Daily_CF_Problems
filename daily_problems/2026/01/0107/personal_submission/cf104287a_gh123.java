import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A104294{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int q=sc.nextInt();
        int[][]grid=new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j]=sc.nextInt();
            }
        }   
        int[][]save=new int[n][n*n+1];
        for (int i = 0; i < save.length; i++) {
            Arrays.fill(save[i], n*n+1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if(i+k>=n||j+k>=n){
                        break;
                    }
                    save[k][grid[i][j]]=Math.min(save[k][grid[i][j]], grid[i+k][j+k]);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = n*n-1; j >=0; j--) {
                save[i][j]=Math.min(save[i][j], save[i][j+1]);
            }
        }
        ArrayList<Integer>list=new ArrayList<>();
        while (q-->0) {
            int a=sc.nextInt(),b=sc.nextInt();
            for (int i = n-1; i >=0; i--) {
                if(save[i][a]<=b){
                    list.add((i+1)*(i+1));
                    break;
                }
            }
        }
        sc.close();
        for (int x : list) {
            System.out.println(x);
        }
    }
}
