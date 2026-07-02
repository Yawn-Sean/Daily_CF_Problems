        void solve() {
            int n = io.nextInt();
            long left = 0, right = 0, middle = 0, res = 0;
            for (int i = 0; i < n; i++) {
                int x = io.nextInt(), y = io.nextInt();
                if (x == y)
                    middle++;
                else if (x < y)
                    left++;
                else
                    right++;
            }
            res += left * right;
            res += middle * (n - middle + n - 1) / 2;
            io.println(res);
        }
