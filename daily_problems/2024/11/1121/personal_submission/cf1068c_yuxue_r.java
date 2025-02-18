import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        List<List<int[]>> pts = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            pts.add(new ArrayList<>());
        }
        for (int i = 1; i <= n; i++) {
            pts.get(i).add(new int[]{i, i});
        }

        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            pts.get(u).add(new int[]{n + i + 1, u});
            pts.get(v).add(new int[]{n + i + 1, v});
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(pts.get(i).size());
            for (int[] x : pts.get(i)) {
                System.out.println(x[0] + " " + x[1]);
            }
        }

        scanner.close();
    }
}
