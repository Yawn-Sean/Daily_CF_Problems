import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        ArrayList<Integer> asterisks = new ArrayList<>();
        ArrayList<Integer> packmen = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '*') {
                asterisks.add(i);
            } else if (s.charAt(i) == 'P') {
                packmen.add(i);
            }
        }

        int l = 0, r = 2 * n, k = asterisks.size();

        while (l <= r) {
            int m = (l + r) / 2;
            int pt = 0;

            for (int p : packmen) {
                if (Math.abs(asterisks.get(pt) - p) > m) continue;
                int left = Math.max(0, p - asterisks.get(pt));
                int right = p + Math.max((m - left) / 2, m - left * 2);
                while (pt < k && asterisks.get(pt) <= right) {
                    pt++;
                }
                if (pt == k) break;
            }

            if (pt == k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        System.out.println(l);
    }
}
