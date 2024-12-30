import java.util.*;
import java.io.*;

public class Main {

    static char[][] grid;
    static int n, m;
    static int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static int[][] dir2 = {{-1, 0}, {1, 0}, {0, 1}};

    static void solve() {
        n = sc.nextInt();
        m = sc.nextInt();
        grid = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '\0') {
                    continue;
                }
                for (char c = 'A'; c <= 'Z'; c++) {
                    if (check(i, j, c)) {
                        grid[i][j] = c;
                        break;
                    }
                    if (check2(i, j, c)) {
                        int y = j - 1;
                        while (y >= 0 && grid[i][y] == c) {
                            y--;
                        }
                        y++;
                        int len = j - y;
                        if (i + len >= n) {
                            continue;
                        }
                        boolean flag = true;
                        o: for (int a = 0; a <= len; a++) {
                            for (int b = 0; b <= len; b++) {
                                if (grid[i + a][j - b] != '\0' && grid[i + a][j - b] != c) {
                                    flag = false;
                                    break o;
                                }
                            }
                        }
                        if (flag) {
                            for (int a = 0; a <= len; a++) {
                                for (int b = 0; b <= len; b++) {
                                    grid[i + a][j - b] = c;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(grid[i][j]);
            }
            out.println();
        }
    }

    static boolean check(int i, int j, char c) {
        int x, y;
        for (int[] d : dir) {
            if (0 <= (x = i + d[0]) && x < n && 0 <= (y = j + d[1]) && y < m && grid[x][y] == c) {
                return false;
            }
        }
        return true;
    }

    static boolean check2(int i, int j, char c) {
        int x, y;
        for (int[] d : dir2) {
            if (0 <= (x = i + d[0]) && x < n && 0 <= (y = j + d[1]) && y < m && grid[x][y] == c) {
                return false;
            }
        }
        return true;
    }
  
}
