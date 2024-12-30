//https://codeforces.com/problemset/submission/281/281820373
import java.util.Scanner;

public class B281 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt(),y=sc.nextInt(),n=sc.nextInt();
        int a,b,c,ak=0,bk=1;
        double k=(double)x/y,m=k;
        sc.close();
        for (b = n; b >=1; b--) {
            c=(int)(k*b);
            for (a = c+1; a>=Math.max(c-1, 0); a--) {
                if(Math.abs(((double)a/b)-k)-m<0.000000000000001){
                    m=Math.abs(((double)a/b)-k);
                    ak=a;
                    bk=b;
                }
            }
        }
        System.out.println(ak+"/"+bk);
    }
}
