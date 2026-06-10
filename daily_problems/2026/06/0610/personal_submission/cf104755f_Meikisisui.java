void solve() {
            int n = io.nextInt(), m = io.nextInt();
            int[] a = new int[n], b = new int[m];
            for (int i = 0; i < n; i++)
                a[i] = io.nextInt();
            for (int i = 0; i < m; i++)
                b[i] = io.nextInt();
            Arrays.sort(a);
            Arrays.sort(b);
            List<Integer> res = new ArrayList<>();
            boolean[] visited = new boolean[m];
            int first = a[0];
            for (int hole : b) {
                int right = 0;
                boolean flag = true;
                for (int point : a) {
                    int tar = hole + 2 * (point - first);
                    while (right < m && b[right] < tar)
                        right++;
                    if (right == m || b[right] != tar) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res.add(2 * first - hole);
                    right = 0;
                    for (int point : a) {
                        int tar = hole + 2 * (point - first);
                        while (right < m && b[right] < tar)
                            right++;
                        visited[right] = true;
                    }
                }
            }
            boolean isOk = true;
            for (boolean i : visited) {
                if (!i) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                io.println("Yes");
                io.println(res.size());
                int k = res.size();
                for (int i = 0; i < k; i++)
                    io.print(res.get(i) + " ");
            } else
                io.println("No");
        }
