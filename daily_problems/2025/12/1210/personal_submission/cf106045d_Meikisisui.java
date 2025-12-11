import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            long r = Long.parseLong(st.nextToken());
            long L = Long.parseLong(st.nextToken());
            double jiao = Double.parseDouble(st.nextToken());
            double len = Math.sin(jiao / 2 / 180 * Math.PI) * r * 2;
            double res = Math.sqrt(L * L - len * len);
            pw.println(res);
        }
        pw.close();
    }

}
