void solve() {
            int n = io.nextInt();
            int k = io.nextInt();
            long[] a = new long[n];
            int beishu = 0;
            String res = "Rami";
            for (int i = 0; i < n; i++) {
                a[i] = io.nextLong();
                if (a[i] % k == 0)
                    beishu++;
            }
            if (beishu == n)
                res = "Rami";
            else if (n - beishu == 2)
                res = "Oussama";
            else if ((n & 1) == 0)
                res = "Oussama";
            else
                res = "Rami";
            io.println(res);
        }
