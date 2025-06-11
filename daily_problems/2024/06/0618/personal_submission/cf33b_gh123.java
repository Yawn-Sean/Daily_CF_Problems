//https://codeforces.com/problemset/submission/33/266253384
import java.util.Arrays;
import java.util.Scanner;

public class B33 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        char[]cs1=sc.next().toCharArray();
        char[]cs2=sc.next().toCharArray();
        int INF=Integer.MAX_VALUE/2;
        int n=sc.nextInt();
        int[][]m=new int[123][123];
        for (int i = 0; i < 123; i++) {
            Arrays.fill(m[i],INF);
        }
        char a;
        char b;
        int w;
        for (int i = 0; i < n; i++) {
            a=sc.next().toCharArray()[0];
            b=sc.next().toCharArray()[0];
            w=sc.nextInt();
            m[a][b]=Math.min(m[a][b], w);
        }
        if(cs1.length!=cs2.length){
            System.out.println(-1);
            return;
        }
        int l=cs1.length;
        int cost=0;
        StringBuilder sb=new StringBuilder();
        for (int k = 97; k < 123; k++) {
            m[k][k]=0;
            for (int i = 97; i < 123; i++) {
                if(m[i][k]==INF){
                    continue;
                }
                for (int j = 97; j < 123; j++) {
                    if(m[k][j]==INF){
                        continue;
                    }
                    m[i][j]=Math.min(m[i][k]+m[k][j], m[i][j]);
                }
            }
        }
        int min=0;
        int pos=0;
        for (int i = 0; i < l; i++) {
            if(cs1[i]!=cs2[i]){
                min=INF;
                for (int j = 97; j < 123; j++) {
                    if(m[cs1[i]][j]+m[cs2[i]][j]<min){
                        min=m[cs1[i]][j]+m[cs2[i]][j];
                        pos=j;
                    }
                }
                sb.append((char)pos);
                if(min==INF){
                    System.out.println(-1);
                    return;
                }
                cost+=min;
            }else{
                sb.append(cs1[i]);
            }
        }
        System.out.println(cost);
        System.out.println(sb.toString());
        sc.close();
    }
}
