import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        double x1 = Double.parseDouble(st.nextToken());
        double y1 = Double.parseDouble(st.nextToken());
        double r1 = Double.parseDouble(st.nextToken());
        st = new StringTokenizer(br.readLine());
        double x2 = Double.parseDouble(st.nextToken());
        double y2 = Double.parseDouble(st.nextToken());
        double r2 = Double.parseDouble(st.nextToken());
        double rLen = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)), res = 0;
        if (r1 > rLen + r2)
            res = r1 - rLen - r2;
        else if (r2 > rLen + r1)
            res = r2 - rLen - r1;
        else if (r1 + r2 > rLen)
            res = 0;
        else
            res = rLen - r1 - r2;
        pw.println(Math.abs(res / 2));
        pw.close();
        br.close();
    }

}
