    static int a, b, c, d, n;
    public static boolean legal(int x, int y){
        if (x >= 0 && x < b && y >= 0 && y < a) return true;
        if (x >= 0 && x < d && y >= a && y < a+c) return true;
        return false;
    }

    public static void solve(){
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        n = sc.nextInt();
        int[] xs = new int[n];
        for (int i = 0; i < n; ++ i){
            xs[i] = sc.nextInt();
        }

        char[][] g = new char[max(b,d)][a+c];
        for (int i = 0; i < max(b,d); ++ i){
            for (int j = 0; j < a+c; ++ j){
                g[i][j] = '.';
            }
        }

        int dir, ix, iy;
        if (d >= b){
            ix = d-1;
            if ((d-b)%2 == 1){
                dir = 1;
                iy = a;
            } else {
                dir = -1;
                iy = a+c-1;
            }
        } else {
            ix = b-1;
            if ((b-d)%2 == 1){
                dir = -1;
                iy = a-1;
            } else {
                dir = 1;
                iy = 0;
            }
        }

        int in = 0;

        while (in < n){

            while (xs[in] > 0){
                g[ix][iy] = (char) (in + 'a');

                if (dir == 1){
                    iy += 1;
                    if (!legal(ix, iy)){
                        iy -= 1;
                        ix -= 1;
                        dir = -1;
                    }
                } else {
                    iy -= 1;
                    if (!legal(ix, iy)){
                        iy += 1;
                        ix -= 1;
                        dir = 1;
                    }
                }

                xs[in] -= 1;
            }

            in += 1;
        }

        out.println("YES");
        for (int i = 0; i < max(b,d); ++ i){
            for (int j = 0; j < a+c; ++ j){
                out.print(g[i][j]);
            }
            out.println();
        }
    }
