import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val g = Array(n) { mutableListOf<Pair<Int, String>>() }

    for (i in 1..<n) {
        val parts = br.readLine().split(" ")
        val p = parts[0].toInt()
        val s = parts[1]
        g[p - 1].add(i to s)
    }
    val t = br.readLine()
    val m = t.length
    val base = 482200539078607UL
    var pPow = 1UL
    var h = 0UL
    for (j in 0..<m) {
        pPow *= base
        h = h * base + t[j].code.toULong()
    }
    var ans = 0L
    val st = mutableListOf(0UL)
    fun dfs(u: Int) {
        for ((v, s) in g[u]) {
            for (c in s) {
                st.add(st.last() * base + c.code.toULong())
                if (st.size > m && st.last() - st[st.size - m - 1] * pPow == h) ans++
            }
            dfs(v)
            repeat(s.length) { st.removeAt(st.lastIndex) }
        }
    }
    dfs(0)
    println(ans)
}
