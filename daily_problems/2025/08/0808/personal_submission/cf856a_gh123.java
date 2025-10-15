//https://codeforces.com/problemset/submission/856/332939799
import java.util.Scanner;

public class A856 {
    static int m=1000001;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int []a=new int[n];
            int[]b=new int[n];
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt();
            }
            boolean[]flag=new boolean[m];
            int id=0;
            for (int i = 1; i <m&&id<n; i++) {
                if(!flag[i]){
                    b[id++]=i;
                    for (int x : a) {
                        for (int y : a) {
                            int bi=i+x-y;
                            if(bi>=1&&bi<m){
                                flag[bi]=true;
                            }
                        }
                    }
                }
            
        }
        System.out.println("YES");
            for (int j = 0; j < n; j++) {
                System.out.print(b[j]+" ");
            }
            System.out.println();
       
    }
     sc.close();
}
}
