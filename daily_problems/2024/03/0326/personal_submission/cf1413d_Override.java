import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] ans = new int[100005];
        int num = 1;
        Stack<Integer> v = new Stack<>();

        for (int i = 1; i <= 2 * n; i++) {
            char ch = scanner.next().charAt(0);
            if (ch == '+') {
                v.push(num++);
            } else {
                int x = scanner.nextInt();
                if (v.isEmpty()) {
                    System.out.println("NO");
                    return;
                } else if (x < ans[v.peek() + 1]) {
                    System.out.println("NO");
                    return;
                }
                ans[v.peek()] = x; 
                v.pop(); 
            }
        }

        System.out.println("YES");
        for (int i = 1; i <= n; i++) {
            System.out.print(ans[i]);
            if (i != n) {
                System.out.print(' ');
            }
        }
    }
}
