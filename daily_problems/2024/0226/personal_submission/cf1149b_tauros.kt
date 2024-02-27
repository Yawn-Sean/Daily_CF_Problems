
import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable

open class FastReader(private val input: InputStream, bufCap: Int = 8192) {
    companion object {
        private const val NC = 0.toChar()
    }

    private val buf = ByteArray(bufCap)
    private var bId = 0
    private var size = 0
    private var c = NC
    private val char: Char
        get() {
            while (bId == size) {
                size = input.read(buf) // no need for checked exceptions
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toInt().toChar()
        }

    private fun isWhitespace(c: Char) = c.code !in 33..126

    private fun skip(): Char {
        var b: Char
        while (char.also { b = it } != NC && isWhitespace(b));
        return b
    }

    fun ns() = buildString {
        while (true) {
            c = char
            if (!isWhitespace(c)) {
                break
            }
        }
        append(c)
        while (true) {
            c = char
            if (isWhitespace(c)) {
                break
            }
            append(c)
        }
    }

    fun ns(n: Int): CharArray {
        val buf = CharArray(n)
        var b = skip()
        var p = 0
        while (p < n && !isWhitespace(b)) {
            buf[p++] = b
            b = char
        }
        return if (n == p) buf else buf.copyOf(p)
    }

    fun ni(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun nl(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun na(n: Int) = IntArray(n) { ni() }
    fun nal(n: Int) = LongArray(n) { nl() }
    fun nad(n: Int) = DoubleArray(n) { nd() }
    fun nm(n: Int, m: Int) = Array(n) { ns(m) }
    fun nmi(n: Int, m: Int) = Array(n) { na(m) }
    fun nd() = ns().toDouble()
    fun nc() = skip()
}

open class FastWriter : Closeable {
    private val writer: PrintWriter

    constructor(output: OutputStream, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(OutputStreamWriter(output), bufCap))
    }

    constructor(writer: Writer, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(writer, bufCap))
    }

    override fun close() {
        writer.flush()
        try {
            writer.close()
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    fun print(b: Boolean) = writer.print(b)
    fun print(c: Char) = writer.print(c)
    fun print(i: Int) = writer.print(i)
    fun print(l: Long) = writer.print(l)
    fun print(f: Float) = writer.print(f)
    fun print(d: Double) = writer.print(d)
    fun print(s: CharArray) = writer.print(s)
    fun print(s: String?) = writer.print(s)
    fun print(obj: Any?) = writer.print(obj)
    fun println() = writer.println()
    fun println(x: Boolean) = writer.println(x)
    fun println(x: Char) = writer.println(x)
    fun println(x: Int) = writer.println(x)
    fun println(x: Long) = writer.println(x)
    fun println(x: Float) = writer.println(x)
    fun println(x: Double) = writer.println(x)
    fun println(x: CharArray) = writer.println(x)
    fun println(x: String) = writer.println(x)
    fun println(x: Any) = writer.println(x)
    fun printf(format: String, vararg args: Any?) = writer.format(format, *args)
    fun flush() = writer.flush()
}

inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }

inline fun iar(size: Int, init: (Int) -> Int = { 0 }) = IntArray(size) { init(it) }


private val bufCap = 65536

private val rd = FastReader(System.`in`, bufCap)

private val wt = FastWriter(System.out, bufCap)

private val INF = 0x3f3f3f3f

private val INF_LONG = 0x3f3f3f3f3f3f3f3fL

private fun solve() {
    // https://codeforces.com/problemset/problem/1149/B
    // 先考虑怎么匹配三个不相交子序列：
    // 预处理主串的子序列状态机，然后匹配三个子序列可以动态规划，总状态就是每个序列位置数量相乘，250^3个状态，dp值表示匹配的最主串最左边位置
    // 那么考虑如何修改：
    // 如果有删除，那什么都不用做，相当于某个子序列位置回退一格，直接查询
    // 如果有新增，那么需要更新，当前长度的dp值，dp[i][j][k] = min(dp[i - 1][j][k] 的下一个 i位置代表的字符位置, dp[i][j - 1][k] 的下一个 j位置代表的字符位置, dp[i][j][k - 1] 的下一个 k位置代表的字符位置)
    // 每次新增时只用更新 250 * 250 个状态，由于最长不超过250，最多的新增数量为 250 + 250 + 250 + 125，总复杂度就是 875 * 250 * 250
    // 枚举 i j k 要写三份差不多重复的代码，原本想通过状压来控制状态，抽象一下dp过程，结果直接TLE，无奈还是得写一大坨
    val (n, q) = rd.ni() to rd.ni()
    val str = rd.ns(n)

    val nearest = ar(n + 2) { iar(26) { n + 1 } }
    for (i in n downTo 0) {
        nearest[i + 1].copyInto(nearest[i])
        if (i > 0) {
            val c = str[i - 1] - 'a'
            nearest[i][c] = i
        }
    }

    val cap = 251
    val seq = ar(3) { iar(cap) }
    val tail = iar(3)
    val dp = ar(cap) { ar(cap) { iar(cap) } }
    dp[0][0][0] = 0
    repeat(q) {
        val op = rd.nc()
        val r = rd.ni() - 1
        if (op == '+') {
            seq[r][tail[r]++] = rd.nc() - 'a'

            if (r == 0) {
                for (j in 0 .. tail[1]) for (k in 0 .. tail[2]) {
                    dp[tail[0]][j][k] = minOf(
                        if (dp[tail[0] - 1][j][k] < n + 1) nearest[dp[tail[0] - 1][j][k] + 1][seq[0][tail[0] - 1]] else n + 1,
                        if (j > 0 && dp[tail[0]][j - 1][k] < n + 1) nearest[dp[tail[0]][j - 1][k] + 1][seq[1][j - 1]] else n + 1,
                        if (k > 0 && dp[tail[0]][j][k - 1] < n + 1) nearest[dp[tail[0]][j][k - 1] + 1][seq[2][k - 1]] else n + 1,
                    )
                }
            } else if (r == 1) {
                for (i in 0 .. tail[0]) for (k in 0 .. tail[2]) {
                    dp[i][tail[1]][k] = minOf(
                        if (dp[i][tail[1] - 1][k] < n + 1) nearest[dp[i][tail[1] - 1][k] + 1][seq[1][tail[1] - 1]] else n + 1,
                        if (i > 0 && dp[i - 1][tail[1]][k] < n + 1) nearest[dp[i - 1][tail[1]][k] + 1][seq[0][i - 1]] else n + 1,
                        if (k > 0 && dp[i][tail[1]][k - 1] < n + 1) nearest[dp[i][tail[1]][k - 1] + 1][seq[2][k - 1]] else n + 1,
                    )
                }
            } else {
                for (i in 0 .. tail[0]) for (j in 0 .. tail[1]) {
                    dp[i][j][tail[2]] = minOf(
                        if (dp[i][j][tail[2] - 1] < n + 1) nearest[dp[i][j][tail[2] - 1] + 1][seq[2][tail[2] - 1]] else n + 1,
                        if (i > 0 && dp[i - 1][j][tail[2]] < n + 1) nearest[dp[i - 1][j][tail[2]] + 1][seq[0][i - 1]] else n + 1,
                        if (j > 0 && dp[i][j - 1][tail[2]] < n + 1) nearest[dp[i][j - 1][tail[2]] + 1][seq[1][j - 1]] else n + 1,
                    )
                }
            }
        } else {
            tail[r] -= 1
        }

        val success = dp[tail[0]][tail[1]][tail[2]] <= n
        wt.println(if (success) "YES" else "NO")
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}
