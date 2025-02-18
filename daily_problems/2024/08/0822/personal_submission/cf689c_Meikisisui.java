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
        long m = Long.parseLong(st.nextToken());
        long res = -1;
        long left = 0, right = Long.MAX_VALUE;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long cnt = 0;
            for (long k = 2; k * k * k <= mid; k++)
                cnt += mid / (k * k * k);
            if (cnt == m) {
                // 找到一个mid满足条件时，继续在左区间尝试找更小的满足条件的
                res = mid;
                right = mid - 1;
            } else if (cnt > m)
                right = mid - 1;
            else
                left = mid + 1;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
