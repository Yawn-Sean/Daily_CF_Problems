import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        if (3 == n) {
            pw.println("-2 1");
            pw.println("-1 0");
            pw.println("1 -1");
            pw.println("2 -1");
            pw.println("1 0");
            pw.println("-1 1");
        } else {
            pw.println("-1 0");
            pw.println("0 -1");
            pw.println("1 -1");
            pw.println((n - 2) + " 0");
            pw.println("1 1");
            pw.println("0 1");
        }
        pw.close();
    }

}
