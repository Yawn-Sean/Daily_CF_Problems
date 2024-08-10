//https://codeforces.com/problemset/submission/1660/272634416
import java.util.Scanner;

public class E1660 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            char[][]a=new char[n][n];
            int[]cntk=new int[n];
            int cnt=0;
            for (int i = 0; i < n; i++) {
                a[i]=sc.next().toCharArray();
                int k=(n-i)%n;
                for (int j = 0; j < cntk.length; j++) {
                    if(a[i][j]=='1'){
                        cnt++;
                        cntk[k]++;
                    }
                    if(k==n-1){
                        k=0;
                    }else{
                        k++;
                    }
                }
            }
            int max=0;
            for (int i = 0; i < n; i++) {
                max=Math.max(max,cntk[i]);
            }
            System.out.println(cnt-max+n-max);
        }
        sc.close();
    }
}
