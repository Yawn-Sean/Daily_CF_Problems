//https://codeforces.com/problemset/submission/1468/316901709
import java.util.Arrays;
import java.util.Scanner;

public class D1468 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int m=sc.nextInt();
            int a=sc.nextInt();
            int b=sc.nextInt();
            int[]arr=new int[m];
            for (int i = 0; i < arr.length; i++) {
                arr[i]=sc.nextInt();
            }
            Arrays.sort(arr);
            int c=Math.min(m, Math.abs(a-b)-1);
            int x;
            if(a<b){
                x=b-1;
            }else{
                x=n-b;
            }
            int ans=0;
            for (int i = c-1; i >=0; i--) {
                if(arr[i]<x){
                    x--;
                    ans++;
                }
            }
            System.out.println(ans);
        }   
        sc.close();
    }
}
