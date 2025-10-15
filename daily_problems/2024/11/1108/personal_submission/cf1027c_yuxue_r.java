import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Map<Integer, Integer> mp = new HashMap<>();

            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                mp.put(x, mp.getOrDefault(x, 0) + 1);
            }

            boolean flg = false;
            List<Integer> tmp = new ArrayList<>();
            for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
                int k = entry.getKey();
                int v = entry.getValue();
                if (v >= 4) {
                    System.out.println(k + " " + k + " " + k + " " + k);
                    flg = true;
                    break;
                }
                if (v >= 2) {
                    tmp.add(k);
                }
            }
            if (!flg) {
                Collections.sort(tmp);
                int x = 1, y = 0;
                for (int i = 1; i < tmp.size(); i++) {
                    int nx = tmp.get(i), ny = tmp.get(i - 1);
                    if (nx * y < x * ny) {
                        x = nx;
                        y = ny;
                    }
                }
                System.out.println(x + " " + x + " " + y + " " + y);
            }
        }

        sc.close();
    }
}
