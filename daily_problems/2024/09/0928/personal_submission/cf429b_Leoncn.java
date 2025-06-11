
public class cf429b_Leoncn {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),m = sc.nextInt();
        int[][] arr  = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        int[][] dp1 = new int[n+2][m+2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp1[i+1][j+1] = Math.max(dp1[i+1][j], dp1[i][j+1]) + arr[i][j];
            }
        }

        int[][] dp2 = new int[n+2][m+2];
        for (int i = n-1; i>=0  ; i--) {
            for (int j = m-1; j >=0 ; j--) {
                dp2[i+1][j+1] = Math.max(dp2[i+1][j+2], dp2[i+2][j+1])+ arr[i][j];
            }
        }

        int[][] dp3 = new int[n+2][m+2];
        for (int i = n-1; i>=0  ; i--) {
            for (int j = 0; j < m; j++) {
                dp3[i+1][j+1] = Math.max(dp3[i+2][j+1], dp3[i+1][j]) + arr[i][j];
            }
        }

        int[][] dp4 = new int[n+2][m+2];
        for (int i = 0; i < n; i++) {
            for (int j = m-1; j >=0 ; j--) {
                dp4[i+1][j+1] = Math.max(dp4[i+1][j+2], dp4[i][j+1]) + arr[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                ans = Math.max(Math.max(ans, dp1[i+1][j]+dp2[i+1][j+2]+dp3[i+2][j+1]+dp4[i][j+1]), Math.max(ans, dp1[i][j+1]+dp2[i+2][j+1]+dp3[i+1][j]+dp4[i+1][j+2]));
            }
        }
        System.out.println(ans);





    }
}
