static int[][] mat;
static int[] rtx, rty, lbx, lby;

static void solve() {
    int n = sc.nextInt();
    mat = new int[n][n];
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (char c : sc.next().toCharArray()) {
            mat[i][j++] = c - '0';
        }
    }
    rtx = new int[n];
    rty = new int[n];
    lbx = new int[n];
    lby = new int[n];
    int ans = 0;
    for (int l = 0, r = n - 1, t = 0, b = n - 1; l <= r; l++, r--, t++, b--) {
        if (l == r) {
            if (val(l, r) == 1) {
                ans++;
            }
            break;
        }
        for (int i = t, j = r, v = 0; j >= l;) {
            if (j == l) {
                mat[i][j--] ^= v;
                continue;
            }
            if ((val(i, j) ^ v) == 0) {
                j--;
                continue;
            }
            int p = j;
            while (j > l && (val(i, j) ^ v) == 1) {
                j--;
            }
            rty[p] ^= 1;
            v ^= 1;
            ans++;
        }
        for (int i = b, j = l, v = 0; i >= t;) {
            if (i == t) {
                mat[i--][j] ^= v;
                continue;
            }
            if ((val(i, j) ^ v) == 0) {
                i--;
                continue;
            }
            int p = i;
            while (i > t && (val(i, j) ^ v) == 1) {
                i--;
            }
            lbx[p] ^= 1;
            v ^= 1;
            ans++;
        }
        if (val(t, l) == 1) {
            ans++;
        }
        for (int i = t, j = r, v = 0; i <= b;) {
            if (i == b) {
                mat[i++][j] ^= v;
                continue;
            }
            if ((val(i, j) ^ v) == 0) {
                i++;
                continue;
            }
            int p = i;
            while (i < b && (val(i, j) ^ v) == 1) {
                i++;
            }
            rtx[p] ^= 1;
            v ^= 1;
            ans++;
        }
        for (int i = b, j = l, v = 0; j <= r;) {
            if (j == r) {
                mat[i][j++] ^= v;
                continue;
            }
            if ((val(i, j) ^ v) == 0) {
                j++;
                continue;
            }
            int p = j;
            while (j < r && (val(i, j) ^ v) == 1) {
                j++;
            }
            lby[p] ^= 1;
            v ^= 1;
            ans++;
        }
        if (val(b, r) == 1) {
            ans++;
        }
    }
    out.println(ans);
}

static int val(int i, int j) {
    if (i == j) {
        return mat[i][j] ^ rtx[i] ^ rty[j] ^ lbx[i] ^ lby[j];
    } else if (i < j) {
        return mat[i][j] ^ rtx[i] ^ rty[j];
    } else {
        return mat[i][j] ^ lbx[i] ^ lby[j];
    }
}
