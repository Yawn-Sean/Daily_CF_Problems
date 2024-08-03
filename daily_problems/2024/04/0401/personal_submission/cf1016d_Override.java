import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int MAXN = 1000 + 100;
        int[] a = new int[MAXN];
        int[] b = new int[MAXN];
        int[][] mp = new int[MAXN][MAXN + 1];

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int suma = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
            suma ^= a[i];
        }
        int sumb = 0;
        for (int j = 1; j <= m; j++) {
            b[j] = scanner.nextInt();
            sumb ^= b[j];
        }
        
        if (suma != sumb) {
            System.out.println("NO");
        } else {
            int s = suma ^ a[n] ^ b[m];
            for (int i = 1; i <= n; i++) {
                mp[i][m] = a[i];
            }
            for (int i = 1; i <= m; i++) {
                mp[n][i] = b[i];
            }
            mp[n][m] = s;
            
            System.out.println("YES");
            for (int i = 1; i <= n; i++) { 
                for (int j = 1; j <= m; j++) {
                    System.out.print(mp[i][j] + " ");
                }
                System.out.println();
            }
        }
        
        scanner.close();
    }
}
