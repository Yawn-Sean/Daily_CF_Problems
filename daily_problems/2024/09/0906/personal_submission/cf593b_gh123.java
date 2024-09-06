//https://codeforces.com/problemset/submission/593/280012554

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
 
/**
 * B593
 */
public class B593 {
 
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long x1=sc.nextLong();
        long x2=sc.nextLong();
        long[][]kb=new long[n][2];
        for (int i = 0; i < n; i++) {
            kb[i][0]=sc.nextLong();
            kb[i][1]=sc.nextLong();
        }
        sc.close();
        Arrays.sort(kb,new Comparator<long[]>() {
            public int compare(long[]a,long[]b){
                long ya=a[0]*x1+a[1];
                long yb=b[0]*x1+b[1];
                if(ya!=yb) return Long.compare(ya, yb);
                return Long.compare(a[0], b[0]);
            }
        });
        long[][]kb2=Arrays.copyOf(kb, n);
        Arrays.sort(kb,new Comparator<long[]>() {
            public int compare(long[]a,long[]b){
                long ya=a[0]*x2+a[1];
                long yb=b[0]*x2+b[1];
                if(ya!=yb) return Long.compare(ya, yb);
                return -Long.compare(a[0], b[0]);
            }
        });
        for (int i = 0; i < n; i++) {
            if(kb[i]!=kb2[i]){
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
