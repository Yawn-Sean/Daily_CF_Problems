import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        List<int[]> points = new ArrayList<>();
        if (n % 2 == 0) {
            points.add(new int[]{0, 0});
            int x = 0, y = 0;
            for (int ez = 0; ez < n / 2 - 1; ez++) {
                y += 25;
                points.add(new int[]{x, y});
                x += 25;
                points.add(new int[]{x, y});
            }
            points.add(new int[]{x, 0});
        } else {
            points.add(new int[]{0, 0});
            int x = 0, y = 0;
            for (int ez = 0; ez < n / 2 - 1; ez++) {
                y += 25;
                points.add(new int[]{x, y});
                x += 25;
                points.add(new int[]{x, y});
            }
            x = Math.max(x, 25);
            points.add(new int[]{x, 0});
            points.add(new int[]{x / 25 * 9, (-x) / 25 * 12});
        }
        int dx = 5, dy = 12;
        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            pw.println((x * dx + y * dy) + " " + ((-x) * dy + y * dx));
        }
        pw.close();
    }

}
