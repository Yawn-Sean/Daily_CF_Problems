import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input1 = scanner.nextLine();
        String input2 = scanner.nextLine();

        char[] s1 = input1.toCharArray();
        char[] s2 = input2.toCharArray();

        int len1 = s1.length - 1, len2 = s2.length - 1;
        int[] a = new int[100020];

        for (int i = len1; i >= 0; i--) {
            if (s1[i] == '1') {
                a[len1 - i] += 1;
            }
        }
        for (int i = len2; i >= 0; i--) {
            if (s2[i] == '1') {
                a[len2 - i] -= 1;
            }
        }

        for (int i = 100000; i >= 2; i--) {
            if (a[i] == 1) {
                a[i - 1]++;
                a[i - 2]++;
            } else if (a[i] >= 2) {
                a[i - 1] += 2;
                a[i - 2] += 2;
            } else if (a[i] == -1) {
                a[i - 1]--;
                a[i - 2]--;
            } else if (a[i] <= -2) {
                a[i - 1] -= 2;
                a[i - 2] -= 2;
            }
            a[i] = 0;
        }

        double x = (Math.sqrt(5) + 1) / 2;
        if (a[1] * x + a[0] > 0) {
            System.out.println(">");
        } else if (a[1] * x + a[0] < 0) {
            System.out.println("<");
        } else {
            System.out.println("=");
        }
    }
}
