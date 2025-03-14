import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int ans1 = 0, ans2 = 0, res = 0;
        Map<String, String> bigMap = new HashMap<>();
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int[] arr = checkBig(a, b, c);
            if (res < arr[2]) {
                ans1 = ez + 1;
                res = arr[2];
                ans2 = 0;
            }
            String key = arr[0] + "~" + arr[1];
            String value = arr[2] + "~" + (ez + 1);
            if (bigMap.containsKey(key)) {
                String[] lastValue = bigMap.get(key).split("~");
                int sum = Integer.parseInt(lastValue[0]) + arr[2];
                // 短边和与mid取最小值
                sum = Math.min(sum, arr[1]);
                if (res < sum) {
                    ans1 = Integer.parseInt(lastValue[1]);
                    ans2 = ez + 1;
                    res = sum;
                }
                if (arr[2] > Integer.parseInt(lastValue[0]))
                    bigMap.put(key, arr[2] + "~" + (ez + 1));
            } else {
                bigMap.put(key, value);
            }
        }
        if (0 == ans2) {
            pw.println(1);
            pw.println(ans1);
        } else {
            pw.println(2);
            pw.println(ans1 + " " + ans2);
        }
        pw.close();
        br.close();
    }

    private static int[] checkBig(int a, int b, int c) {
        int[] res = new int[3];
        if (a >= b && a >= c) {
            res[0] = a;
            if (b >= c) {
                res[1] = b;
                res[2] = c;
            } else {
                res[1] = c;
                res[2] = b;
            }
        } else if (a >= b && a <= c) {
            res[0] = c;
            res[1] = a;
            res[2] = b;
        } else if (a <= b && a >= c) {
            res[0] = b;
            res[1] = a;
            res[2] = c;
        } else if (a <= b && a <= c) {
            res[2] = a;
            if (b >= c) {
                res[0] = b;
                res[1] = c;
            } else {
                res[0] = c;
                res[1] = b;
            }
        }
        return res;
    }

}
