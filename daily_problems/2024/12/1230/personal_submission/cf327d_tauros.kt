private fun solve() {
    // https://codeforces.com/problemset/submission/327/299331025
    val (n, m) = rd.ni() to rd.ni()
    val grid = ar(n) { car(m) { rd.nc() } }

    val ans = mutableListOf<IntArray>()
    val vis = ar(n) { bar(m) }
    val ops = iao(-1, 0, 1, 0, -1)
    val stack = dq<IntArray>()
    for (i in 0 until n) for (j in 0 until m) {
        if (vis[i][j] || grid[i][j] == '#') continue
        stack.addLast(iao(0, i, j))
        vis[i][j] = true
        while (stack.isNotEmpty()) {
            val (op, x, y) = stack.removeLast()
            if (op == 0) {
                ans.add(iao(0, x, y))
                if (x != i || y != j) {
                    stack.addLast(iao(-1, x, y))
                }
                for (o in 0 until 4) {
                    val (nx, ny) = x + ops[o] to y + ops[o + 1]
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] == '#') continue
                    stack.addLast(iao(0, nx, ny))
                    vis[nx][ny] = true
                }
            } else {
                ans.add(iao(1, x, y))
                ans.add(iao(2, x, y))
            }
        }
    }
    wt.println(ans.size)
    wt.print(buildString {
        for ((op, i, j) in ans) {
            append(if (op == 0) 'B' else if (op == 1) 'D' else 'R')
            append(' ')
            append(i + 1)
            append(' ')
            append(j + 1)
            append('\n')
        }
    })
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}