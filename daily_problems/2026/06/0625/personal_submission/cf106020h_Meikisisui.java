void solve() {
            int n = io.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = io.nextInt();
            long res = 0;
            int start = 0;
            for (int i = 0; i <= n; i++) {
                if (i == n || a[i] >= 3) {
                    if (start < i)
                        res += calc(a, start, i - 1);
                    start = i + 1;
                }
            }
            io.println(res);
        }

        static long calc(int[] a, int l, int r) {
            return mex2(a, l, r) + mex3(a, l, r);
        }

        static long mex3(int[] a, int l, int r) {
            List<int[]> list = new ArrayList<>();
            for(int i = l; i <= r; i++) {
                if (a[i] != 0)
                    list.add(new int[]{i, a[i]});
            }
            long res = 0;
            int m = list.size();
            for (int i = 1; i < m; i++) {
                int[] p = list.get(i - 1), q = list.get(i);
                if (p[1] + q[1] != 3)
                    continue;
                long pre = i >= 2 ? list.get(i - 2)[0] : l - 1;
                long next = i < m - 1 ? list.get(i + 1)[0] : r + 1;
                res += (p[0] - pre) * (next - q[0]);
                if (q[0] == p[0] + 1)
                    res--;
            }
            return res;
        }

        static long mex2(int[] a, int l, int r) {
            long res = 0;
            int tl = l;
            for (int i = l; i <= r + 1; i++) {
                if (i == r + 1 || a[i] == 2) {
                    if (tl < i) {
                        List<Integer> list = new ArrayList<>();
                        for (int j = tl; j < i; j++)
                            if (a[j] == 1)
                                list.add(j);
                        int m = list.size();
                        for (int k = 1; k < m; k++) {
                            int p = list.get(k - 1), q = list.get(k);
                            long pre = k >= 2 ? list.get(k - 2) : tl - 1;
                            long next = k < m - 1 ? list.get(k + 1) : i;
                            res += (p - pre) * (next - q);
                            if (q == p + 1)
                                res--;
                        }
                    }
                    tl = i + 1;
                }
            }
            return res;
        }
