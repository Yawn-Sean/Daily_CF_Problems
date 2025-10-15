//https://codeforces.com/problemset/submission/549/336565617
import java.util.Scanner;

public class D549 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        char[][]cs=new char[n][m];
        for (int i = 0; i < n; i++) {
            cs[i]=sc.next().toCharArray();
        }   
        int[][]ans=new int[n][m];
        int cnt=0;
        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >=0; j--) {
                char c=cs[i][j];
                int val;
                if(c=='B'){
                    val=-1-ans[i][j];
                }else{
                    val=1-ans[i][j];
                }
                if(val==0)continue;
                cnt++;
                for (int x = 0; x <=i; x++) {
                    for (int y = 0; y <=j; y++) {
                        ans[x][y]+=val;
                    }
                }
            }
        }
        System.out.println(cnt);
        sc.close();
    }
}
