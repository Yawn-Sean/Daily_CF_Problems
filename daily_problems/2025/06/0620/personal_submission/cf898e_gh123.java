//https://codeforces.com/problemset/submission/898/325215294
import java.util.Arrays;
import java.util.Scanner;

public class E898 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]a=new int[n][2];
        for (int i = 0; i < a.length; i++) {
            a[i][0]=sc.nextInt();
        }
        sc.close();
        for (int i = 0; i < n; i++) {
            int x=a[i][0];
            int s=(int)Math.sqrt(x);
            if(s*s==x){
                a[i][1]=0;
            }else{
                a[i][1]=Math.min(x-s*s, (s+1)*(s+1)-x);
            }
        }
        Arrays.sort(a,(x,y)->x[1]==y[1]?x[0]-y[0]:x[1]-y[1]);
        // for (int i = 0; i < a.length; i++) {
        //     System.out.println(a[i][0]+" "+a[i][1]);
        // }
        long sum=0;
        boolean flag=true;
        for (int i = 0; i < n/2; i++) {
            if(a[i][1]>0){
                flag=false;
            }
            sum+=a[i][1];
        }
        if(flag){
            for (int i = n/2; i < a.length; i++) {
                if(a[i][1]==0){
                    sum++;
                }
                if(a[i][0]==0){
                    sum++;
                }
            }
        }
        System.out.println(sum);
    }
}
