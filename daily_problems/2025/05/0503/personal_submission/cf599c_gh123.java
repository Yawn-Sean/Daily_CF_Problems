//https://codeforces.com/problemset/submission/599/318178899
import java.util.Arrays;
import java.util.Scanner;

public class C599 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        int[]b=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            b[i]=a[i];
        }   
        sc.close();
        Arrays.sort(b);
        int cnt=0;
        int prea=0,preb=0;
        for (int i = 0; i < n; i++) {
            prea+=a[i];
            preb+=b[i];
            if(prea==preb){
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
