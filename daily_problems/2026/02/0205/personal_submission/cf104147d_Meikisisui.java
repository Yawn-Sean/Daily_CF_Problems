import java.io.*;
import java.util.StringTokenizer;

public class Test6 {

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("dotak.in")));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            long sum = (long) n * k;
            sum %= (k + 1);
            if ((sum & 1) == 1 || sum == k)
                pw.println("Omda");
            else
                pw.println("Teemo");
        }
        pw.close();
    }

}
