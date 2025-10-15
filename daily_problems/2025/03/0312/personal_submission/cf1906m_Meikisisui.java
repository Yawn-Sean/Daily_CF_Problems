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
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] arr = new long[n];
        long sum = 0, maxNode = 0;
        for (int ez = 0; ez < n; ez++) {
            arr[ez] = Long.parseLong(st.nextToken());
            sum += arr[ez];
            maxNode = Math.max(maxNode, arr[ez]);
        }
        if (maxNode >= (sum - maxNode) * 2)
            pw.println(sum - maxNode);
        else
            pw.println(sum / 3);
        pw.close();
        br.close();
    }

}
