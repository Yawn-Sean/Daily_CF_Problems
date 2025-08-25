//https://codeforces.com/problemset/submission/160/334610638
import java.util.Arrays;
import java.util.Scanner;

public class C160 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long k=sc.nextLong()-1;
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        Arrays.sort(a);
        int l=0;
        int r=-1;
        while (l<n) {
             r=l;
            while (r<n&&a[r]==a[l]) {
                r++;
            }
            if(k<1l*(r-l)*n){
                break;
            }
            k-=1l*(r-l)*n;
            l=r;
        }
        System.out.println(a[l]+" "+a[(int)(k/(r-l))]);
        sc.close();
    }
}
