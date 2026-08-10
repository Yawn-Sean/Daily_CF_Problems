
        void solve() {
            int r = io.nextInt(), c = io.nextInt(), m = io.nextInt(), k = io.nextInt();
            int mn = Math.min(r, c), mx = Math.max(r, c);
            if (k > mn || m < k || m > k * mx) {
                io.println("NO");
                return;
            }
            boolean isRow = (r <= c) ? false : true;
            io.println("YES");
            m -= k;
            char[][] grid = new char[r][c];
            for (int i = 0; i < k; i++)
                grid[i][i] = '#';
            boolean isOk = false;
            for (int i = 0; isRow ? i < r : i < k; i++) {
                for (int j = 0; !isRow ? j < c : j < k; j++) {
                    if (i == j)
                        continue;
                    if (m > 0) {
                        m--;
                        grid[i][j] = '#';
                    } else
                        isOk = true;
                    if (isOk)
                        break;
                }
                if (isOk)
                    break;
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == '#')
                        io.print('#');
                    else
                        io.print('.');
                }
                io.println();
            }
        }
