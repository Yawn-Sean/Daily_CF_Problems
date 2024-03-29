import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable

open class FastReader(private val input: InputStream, bufCap: Int = 8192) {
    companion object { private const val NC = 0.toChar() }
    private val buf = ByteArray(bufCap)
    private var bId = 0
    private var size = 0
    private var c = NC
    private val char: Char
        get() {
            while (bId == size) { size = input.read(buf); if (size == -1) return NC; bId = 0 }
            return buf[bId++].toInt().toChar()
        }
    private fun isWhitespace(c: Char) = c.code !in 33..126
    private fun skip(): Char { var b: Char; while (char.also { b = it } != NC && isWhitespace(b)); return b }
    fun ns() = buildString {
        while (true) { c = char; if (!isWhitespace(c)) break }; append(c);
        while (true) { c = char; if (isWhitespace(c)) break; append(c) }
    }
    fun ns(n: Int): CharArray {
        val buf = CharArray(n); var (b, p) = skip() to 0
        while (p < n && !isWhitespace(b)) { buf[p++] = b;b = char }
        return if (n == p) buf else buf.copyOf(p)
    }
    fun ni(): Int {
        var neg = false; if (c == NC) c = char
        while (c < '0' || c > '9') { if (c == '-') neg = true;c = char }
        var res = 0; while (c in '0'..'9') { res = (res shl 3) + (res shl 1) + (c - '0'); c = char }
        return if (neg) -res else res
    }
    fun nl(): Long {
        var neg = false; if (c == NC) c = char
        while (c < '0' || c > '9') { if (c == '-') neg = true; c = char }
        var res = 0L; while (c in '0'..'9') { res = (res shl 3) + (res shl 1) + (c - '0'); c = char }
        return if (neg) -res else res
    }
    fun na(n: Int) = IntArray(n) { ni() }; fun nal(n: Int) = LongArray(n) { nl() }; fun nad(n: Int) = DoubleArray(n) { nd() }
    fun nm(n: Int, m: Int) = Array(n) { ns(m) }; fun nmi(n: Int, m: Int) = Array(n) { na(m) }
    fun nd() = ns().toDouble(); fun nc() = skip()
}
open class FastWriter : Closeable {
    private val writer: PrintWriter
    constructor(output: OutputStream, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(OutputStreamWriter(output), bufCap))
    }
    constructor(writer: Writer, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(writer, bufCap))
    }
    override fun close() { writer.flush(); try { writer.close() } catch (e: Exception) { e.printStackTrace() } }
    fun print(b: Boolean) = writer.print(b); fun print(c: Char) = writer.print(c); fun print(i: Int) = writer.print(i)
    fun print(l: Long) = writer.print(l); fun print(f: Float) = writer.print(f); fun print(d: Double) = writer.print(d)
    fun print(s: CharArray) = writer.print(s); fun print(s: String?) = writer.print(s);
    fun print(obj: Any?) = writer.print(obj)
    fun println() = writer.println(); fun println(x: Boolean) = writer.println(x); fun println(x: Char) = writer.println(x)
    fun println(x: Int) = writer.println(x); fun println(x: Long) = writer.println(x); fun println(x: Float) = writer.println(x)
    fun println(x: Double) = writer.println(x); fun println(x: CharArray) = writer.println(x); fun println(x: String) = writer.println(x)
    fun println(x: Any) = writer.println(x)
    fun printf(format: String, vararg args: Any?) = writer.format(format, *args)
    fun flush() = writer.flush()
}
inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
inline fun bar(size: Int, init: (Int) -> Boolean = { false }) = BooleanArray(size) { init(it) }
inline fun iar(size: Int, init: (Int) -> Int = { 0 }) = IntArray(size) { init(it) }

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/226/D
    // 不会做，太神奇了
    // 每次找一个负数的行或者列，进行翻转
    // 考虑翻转后的矩阵总和一定是上升的，最小上升2（-1变成1）
    // 每次操作一定会让矩阵总和上升，由于值域是[-100, 100]，所以总和最大不会超过100*n*m
    // 从-100*n*m到100*n*m最多不会超过100*n*m次操作
    // 要么最后没有一个为负数的行或列，要么就最多做100*n*m次操作
    // 每次操作O(n)或O(m)，所以总复杂度是100*n*m*max(n, m)，最多不超过100的4次方
    val (n, m) = rd.ni() to rd.ni()
    val grid = ar(n) { rd.na(m) }

    val (rows, cols) = iar(n) to iar(m)
    for (i in 0 until n) for (j in 0 until m) {
        rows[i] += grid[i][j]
        cols[j] += grid[i][j]
    }

    val (rOp, cOp) = bar(n) to bar(m)
    while (true) {
        val r = (0 until n).firstOrNull { rows[it] < 0 } ?: -1
        if (r != -1) {
            rows[r] *= -1
            for (j in 0 until m) {
                cols[j] -= grid[r][j] shl 1
                grid[r][j] *= -1
            }
            rOp[r] = !rOp[r]
            continue
        }
        val c = (0 until m).firstOrNull { cols[it] < 0 } ?: -1
        if (c == -1) break
        cols[c] *= -1
        for (i in 0 until n) {
            rows[i] -= grid[i][c] shl 1
            grid[i][c] *= -1
        }
        cOp[c] = !cOp[c]
    }

    val ans1 = (0 until n).filter { rOp[it] }.map { it + 1 }
    val ans2 = (0 until m).filter { cOp[it] }.map { it + 1 }
    wt.print(ans1.size)
    for (res in ans1) wt.print(" $res")
    wt.println()
    wt.print(ans2.size)
    for (res in ans2) wt.print(" $res")
    wt.println()
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}