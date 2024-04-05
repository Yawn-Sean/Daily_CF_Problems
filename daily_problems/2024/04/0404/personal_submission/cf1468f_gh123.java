import java.awt.Point;
import java.util.HashMap;
import java.util.Scanner;
//https://codeforces.com/problemset/submission/1468/254921679

public class F1468 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            HashMap<Point,Integer>map=new HashMap<>();
            int n=sc.nextInt();
            for (int i = 0; i < n; i++) {
                int x1=sc.nextInt();
                int y1=sc.nextInt();
                int x2=sc.nextInt();
                int y2=sc.nextInt();
                int gcd=gcd(Math.abs(x2-x1),Math.abs(y2-y1));
                int dx=(x2-x1)/gcd;
                int dy=(y2-y1)/gcd;
                Point p=new Point(dx,dy);
                map.put(p, map.getOrDefault(p, 0)+1);
            }
            long ans=0;
            for (Point p : map.keySet()) {
                int val=map.get(p);
                int cnt=map.getOrDefault(new Point(-p.x,-p.y), 0);
                ans+=1l*val*cnt;
            }
            System.out.println(ans/2);
        }
        sc.close();
    }
    public static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
}
