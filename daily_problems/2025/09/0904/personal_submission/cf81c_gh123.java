//https://codeforces.com/problemset/submission/81/336816976
import java.util.Arrays;
import java.util.Scanner;

public class C81 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int[][]arr=new int[n][3];
        for (int i = 0; i < arr.length; i++) {
            arr[i][0]=sc.nextInt();
            arr[i][1]=i;
        }
        if(a==b){
            for (int i = 0; i < a; i++) {
                System.out.print(1+" ");
            }
            for (int i = 0; i < b; i++) {
                System.out.print(2+" ");
            }
        }
        else if(a>b){
            Arrays.sort(arr,(x,y)->x[0]-y[0]);
            for (int i = 0; i < a; i++) {
                arr[i][2]=1;
            }
            for (int i = a; i < arr.length; i++) {
                arr[i][2]=2;
            }
            Arrays.sort(arr,(x,y)->x[1]-y[1]);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i][2]+" ");
            }
            System.out.println();
        }else if(a<b){
            Arrays.sort(arr,(x,y)->y[0]-x[0]);
            for (int i = 0; i < a; i++) {
                arr[i][2]=1;
            }
            for (int i = a; i < arr.length; i++) {
                arr[i][2]=2;
            }
            Arrays.sort(arr,(x,y)->x[1]-y[1]);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i][2]+" ");
            }
            System.out.println();
        }
        sc.close();
    }    
}
