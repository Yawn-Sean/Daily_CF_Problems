import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        if (1 == n) {
            pw.println("1");
            pw.println("1");
        } else if (2 == n)
            pw.println("-1");
        else {
            pw.println(3 << (n - 2));
            pw.print("1 2");
            for (int ez = 0; ez < n - 2; ez++)
                pw.print(" " + (3 << ez));
        }
        pw.close();
    }

}
