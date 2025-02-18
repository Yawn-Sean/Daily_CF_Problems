import java.io.*;
import java.util.*;
public class Main {
    static Scanner sc = new Scanner(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int x1= 110, y1 = 110, x2 = -110, y2 = -110;
        for(int i = 0; i < 4; i ++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            x1 = Math.min(x1, x);
            y1 = Math.min(y1, y);
            x2 = Math.max(x2, x);
            y2 = Math.max(y2, y);
        }
        int minx = 110, miny = 110, maxx = -110, maxy = -110;
        for(int i = 0; i < 4; i ++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            minx = Math.min(minx, x);
            maxx = Math.max(maxx, x);
            miny = Math.min(miny, y);
            maxy = Math.max(maxy, y);
        }
        int cx = (minx + maxx) >> 1;
        int cy = (miny + maxy) >> 1;
        boolean ok = false;
        for(int i = minx; i <= cx; i ++){
            for(int j = cy - (i - minx); j <= cy + (i - minx); j ++){
                if(i >= x1 && i <= x2 && j >= y1 && j <= y2) ok = true;
            }
        }
        for(int i = cx; i <= maxx; i ++){
            for(int j = cy - (maxx - i); j <= cy + (maxx - i); j ++){
                if(i >= x1 && i <= x2 && j >= y1 && j <= y2) ok = true;
            }
        }
        pw.println(ok ? "YES" : "NO");
        pw.flush();
    }   
}
