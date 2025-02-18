import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long h = Long.parseLong(st.nextToken());
        long n = Long.parseLong(st.nextToken());
        long cnt = 1;
        for (int ez = 0; ez < h - 1; ez++)
            cnt += cnt;
        long res = 0;
        boolean isLeft = true;
        for (int ez = 0; ez < h; ez++) {
            res++;
            if ((isLeft && n > cnt) || (!isLeft && n <= cnt))
                res += cnt + cnt - 1;
            else
                isLeft = !isLeft;
            if (n > cnt)
                n -= cnt;
            cnt = cnt >> 1;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
