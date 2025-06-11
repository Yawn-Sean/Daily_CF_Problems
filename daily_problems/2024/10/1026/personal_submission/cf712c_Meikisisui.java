import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        // 正难则反……
        int to = Integer.parseInt(st.nextToken());
        int from = Integer.parseInt(st.nextToken());
        int max = from, middle = from, min = from, cnt = 0;
        while (max < to) {
            int temp = middle + max - 1;
            min = middle;
            middle = max;
            max = temp;
            cnt++;
        }
        pw.println(cnt + 2);
        pw.close();
        f.close();
    }

}
