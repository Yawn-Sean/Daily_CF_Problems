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
        int t = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < t; ez++) {
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            HashMap<Integer, Integer> map = new HashMap<>();
            st = new StringTokenizer(f.readLine());
            ArrayList<Integer> list = new ArrayList<>();
            for (int vn = 0; vn < n; vn++) {
                int temp = Integer.parseInt(st.nextToken());
                if (map.containsKey(temp)) {
                    // 枚举出现两次且每出现两次的情况
                    list.add(temp);
                    map.remove(temp);
                } else
                    map.put(temp, 1);
            }
            Collections.sort(list);
            int a = 0, b = 0;
            double min = Double.MAX_VALUE;
            for (int vn = 0; vn < list.size() - 1; vn++) {
                int x = list.get(vn);
                int y = list.get(vn + 1);
                // 换元可得求x + 1/x 的最小值，即x最接近1，两条边最接近比例时
                double temp = (double) y / x;
                if (temp < min) {
                    a = x;
                    b = y;
                    min = temp;
                }
            }
            pw.println(a + " " + a + " " + b + " " + b);
        }
        pw.close();
        f.close();
    }

}
