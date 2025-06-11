import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        double y1 = Double.parseDouble(st.nextToken());
        double y2 = Double.parseDouble(st.nextToken());
        double yw = Double.parseDouble(st.nextToken());
        double xb = Double.parseDouble(st.nextToken());
        double yb = Double.parseDouble(st.nextToken());
        double r = Double.parseDouble(st.nextToken());
        double xw = xb * (yw - y1 - 2 * r) / (2 * yw - y1 - yb - 3 * r);
        double start = (yw - y1 - 2 * r) / xw;
        double end = y1 + r * (1 + Math.sqrt(1 + Math.pow(start, 2)));
        if (y2 < end)
            pw.println("-1");
        else
            pw.println(xw);
        pw.close();
        f.close();
    }

}
