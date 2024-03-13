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
inline fun findFirst(n: Int, judge: (Int) -> Boolean): Int {
    var l = 0
    var r = n
    while (l < r) {
        val mid = l + (r - l) / 2
        if (judge(mid)) r = mid
        else l = mid + 1
    }
    return l
}
inline fun findFirst(l: Int, r: Int, judge: (Int) -> Boolean) = findFirst(r - l) { judge(it + l) } + l
fun sqrt(n: Long): Long {
    if (n == 0L) return 0
    var x: Long = 1
    var decreased = false
    while (true) {
        val nx = x + n / x shr 1
        if (x == nx || nx > x && decreased) break
        decreased = nx < x
        x = nx
    }
    return x
}
data class IPoint2(val x: Int, val y: Int) {
    fun toVector() = IVector2(x, y)
    operator fun plus(other: IVector2) = IPoint2(x + other.x, y + other.y)
    operator fun minus(other: IVector2) = IPoint2(x - other.x, y - other.y)
    operator fun minus(other: IPoint2) = IVector2(x - other.x, y - other.y)
    override fun equals(other: Any?): Boolean {
        return if (other === this) true
        else if (other !is IPoint2) false
        else x == other.x && y == other.y
    }
    override fun hashCode() = x.hashCode() xor y.hashCode()
}
data class IVector2(val x: Int, val y: Int) {
    fun len2() = x.toLong() * x + y.toLong() * y
    fun len() = sqrt(len2())
    operator fun plus(other: IVector2) = IVector2(x + other.x, y + other.y)
    operator fun minus(other: IVector2) = IVector2(x - other.x, y - other.y)
    // cos
    infix fun dot(other: IVector2) = x.toLong() * other.x + y.toLong() * other.y
    // sin
    infix fun cross(other: IVector2) = x.toLong() * other.y - other.x * y.toLong()
    infix fun isParallel(other: IVector2) = (this cross other) == 0L
    infix fun isPerpendicular(other: IVector2) = (this dot other) == 0L
    infix fun side(other: IVector2) = (this cross other).let { if (it < 0) -1 else if (it > 0) 1 else 0 }
    override fun equals(other: Any?): Boolean {
        return if (other === this) true
        else if (other !is IVector2) false
        else x == other.x && y == other.y
    }
    override fun hashCode() = x.hashCode() xor y.hashCode()
}

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/166/B
    // A是凸多边形，那么B只要每个点都在A内就好
    // 多边形可以切成若干个三角形，二分点在那个三角形，判断下在不在里面，叉乘搞搞就好
    // 给出的点的顺序是CW的，reverse一下就是CCW
    val n = rd.ni()
    val aPoints = ar(n) { IPoint2(rd.ni(), rd.ni()) }.apply { reverse() }
    val m = rd.ni()
    val bPoints = ar(m) { IPoint2(rd.ni(), rd.ni()) }

    //            /|← 点z
    //          /  |
    // out    /    |
    //      /  in  |
    //    /        |  out
    //  /__________|
    // ↑ 点x  out  ↑ 点y
    // fixed点x为A的CCW序的第一个点，通过叉乘关系二分出点y和点z
    // 如果二分到 xz边在A之外 或 xy边在A之外 那么失败
    // 如果 xy边为A的边界 或 xz边为A的边界 此时如果 xb和xy共线 或 xb和xz共线 那么失败
    // 其它情况下，仅需判断 yb向量在yz向量左侧 否则失败
    val fixed = aPoints[0]
    for (point in bPoints) {
        val bVector = point - fixed
        val left = findFirst(1, n) { bVector cross (aPoints[it] - fixed) > 0 }
        if (left == 1 || left == n) {
            // xz边在A之外 或 xy边在A之外
            wt.println("NO"); return
        }
        if (left == n - 1 && (aPoints[left] - fixed) isParallel bVector ||
            left == 2 && (aPoints[left - 1] - fixed) isParallel bVector) {
            // (xz边为A的边界 且 xb和xz共线) 或 (xy边为A的边界 且 xb和xy共线)
            wt.println("NO"); return
        }
        val bound = aPoints[left] - aPoints[left - 1]
        val inner = point - aPoints[left - 1]
        if (bound cross inner <= 0) {
            // yb向量不在yz向量左侧
            wt.println("NO"); return
        }
    }
    wt.println("YES")
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}