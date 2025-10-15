import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            String[] grid = new String[n];
            for (int i = 0; i < n; i++) {
                grid[i] = scanner.next();
            }
            int[] cnt1 = new int[n];
            int[] cnt2 = new int[m];
            boolean f0 = true;
            boolean f5 = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i].charAt(j) == 'A') {
                        cnt1[i]++;
                        cnt2[j]++;
                        f5 = false;
                    } else {
                        f0 = false;
                    }
                }
            }

            if (f0) System.out.println("0");
            else if (f5) System.out.println("MORTAL");
            else if (cnt1[0] == m || cnt1[n - 1] == m || cnt2[0] == n || cnt2[m - 1] == n) System.out.println("1");
            else if (grid[0].charAt(0) == 'A' || grid[0].charAt(m - 1) == 'A' || grid[n - 1].charAt(0) == 'A' || grid[n - 1].charAt(m - 1) == 'A' || maxElement(cnt1) == m || maxElement(cnt2) == n) System.out.println("2");
            else if (cnt1[0] > 0 || cnt1[n - 1] > 0 || cnt2[0] > 0 || cnt2[m - 1] > 0) System.out.println("3");
            else System.out.println("4");
        }
        scanner.close();
    }

    private static int maxElement(int[] array) {
        int max = array[0];
        for (int value : array) {
            if (value > max) {
                max = value;
            }
        }
        return max;
    }
}
