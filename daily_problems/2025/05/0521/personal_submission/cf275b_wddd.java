void solve() {
    int n = is.ni();
    int m = is.ni();
    char[][] grid = is.nm(n, m);

    List<int[]> rowRanges = new ArrayList<>();

    for (int i = 0; i < n; i++) {
        int left = -1;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                left = j;
                break;
            }
        }
        int right = m;
        for (int j = m - 1; j >= 0; j--) {
            if (grid[i][j] == 'B') {
                right = j;
                break;
            }
        }
        if (left != -1 && right != m) {
            for (int j = left; j <= right; j++) {
                if (grid[i][j] == 'W') {
                    out.println("NO");
                    return;
                }
            }
            rowRanges.add(new int[] {left, right});
        }
    }

    List<int[]> colRanges = new ArrayList<>();
    for (int j = 0; j < m; j++) {
        int top = -1;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'B') {
                top = i;
                break;
            }
        }
        int bottom = n;
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][j] == 'B') {
                bottom = i;
                break;
            }
        }
        if (top != -1 && bottom != n) {
            for (int i = top; i <= bottom; i++) {
                if (grid[i][j] == 'W') {
                    out.println("NO");
                    return;
                }
            }
            colRanges.add(new int[] {top, bottom});
        }
    }

    if (validRanges(rowRanges) && validRanges(colRanges)) {
        out.println("YES");
    } else {
        out.println("NO");
    }
}

private boolean validRanges(List<int[]> ranges) {
    Collections.sort(ranges, (a, b) -> {
        if (a[0] != b[0]) {
            return Integer.compare(a[0], b[0]);
        } else {
            return Integer.compare(b[1], a[1]);
        }
    });

    for (int i = 0; i < ranges.size(); i++) {
        int[] curr = ranges.get(i);
        for (int j = i + 1; j < ranges.size(); j++) {
            if (ranges.get(j)[1] > curr[1]) {
                return false;
            }
        }
    }

    return true;
}
