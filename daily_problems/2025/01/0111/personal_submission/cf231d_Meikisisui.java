import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), z = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int x1 = Integer.parseInt(st.nextToken()), y1 = Integer.parseInt(st.nextToken()), z1 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()),
                d = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken()), ff = Integer.parseInt(st.nextToken());
        int res = 0;
        if (y < 0)
            res += a;
        if (y > y1)
            res += b;
        if (x < 0)
            res += e;
        if (x > x1)
            res += ff;
        if (z < 0)
            res += c;
        if (z > z1)
            res += d;
        pw.println(res);
        pw.close();
        f.close();
    }

}
