//https://codeforces.com/problemset/submission/793/317134296
import java.util.Scanner;

//村长是怎么想到这种办法的，真厉害。。。
public class B793 {
    static char[][]cs;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        cs=new char[n][m];
        for (int i = 0; i < n; i++) {
            cs[i]=sc.next().toCharArray();
        }   
        sc.close();
        int sx=0,sy=0,tx=0,ty=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(cs[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                if(cs[i][j]=='T'){
                    tx=i;
                    ty=j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if(check(sx,sy,i,sy)&&check(i,sy,i,ty)&&check(i, ty, tx, ty)){
                System.out.println("Yes");
                return;
            }
        }
        for (int i = 0; i < m; i++) {
            if(check(sx, sy, sx, i)&&check(sx, i, tx, i)&&check(tx, i, tx, ty)){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
   static boolean check(int x1,int y1,int x2,int y2){
        if(x1>x2){
            int tem=x1;
            x1=x2;
            x2=tem;
        }
        if(y1>y2){
            int tem=y1;
            y1=y2;
            y2=tem;
        }
        for (int i = x1; i <=x2; i++) {
            for (int j = y1; j <=y2; j++) {
                if(cs[i][j]=='*'){
                    return false;
                }
            }
        }
        return true;
    }
}
