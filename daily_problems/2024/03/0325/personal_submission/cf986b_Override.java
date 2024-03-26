import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            while (a[i] != i) {
                swap(a, i, a[i]);
                cnt++;
            }
        }

        if ((3 * n - cnt) % 2 == 1) {
            System.out.println("Um_nik");
        }
        if ((7 * n + 1 - cnt) % 2 == 1) {
            System.out.println("Petr");
        }

        scanner.close();
    }

    // Swap function for array elements
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
