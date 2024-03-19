import kotlin.math.abs
import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable
import kotlin.math.sqrt

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
data class DPoint2(val x: Double, val y: Double) {
    fun toVector() = DVector2(x, y)
    operator fun plus(other: DVector2) = DPoint2(x + other.x, y + other.y)
    operator fun minus(other: DVector2) = DPoint2(x - other.x, y - other.y)
    operator fun minus(other: DPoint2) = DVector2(x - other.x, y - other.y)
    override fun equals(other: Any?): Boolean {
        return if (other === this) true
        else if (other !is DPoint2) false
        else x == other.x && y == other.y
    }
    override fun hashCode() = x.hashCode() xor y.hashCode()
    override fun toString() = "($x,$y)"
}
data class DVector2(val x: Double, val y: Double) {
    fun len2() = x * x + y * y
    fun len() = sqrt(len2())
    operator fun plus(other: DVector2) = DVector2(x + other.x, y + other.y)
    operator fun minus(other: DVector2) = DVector2(x - other.x, y - other.y)
    operator fun times(scale: Double) = DVector2(x * scale, y * scale)
    // cos
    infix fun dot(other: DVector2) = x * other.x + y * other.y
    // sin
    infix fun cross(other: DVector2) = x * other.y - other.x * y
    infix fun isParallel(other: DVector2) = abs(this cross other) < 1e-6
    infix fun isPerpendicular(other: DVector2) = abs(this dot other) < 1e-6
    infix fun side(other: DVector2) = (this cross other).let { if (it < 0) -1 else if (it > 0) 1 else 0 }
    fun perpVector() = DVector2(-y, x)
    fun normalized() = this * (1 / len())
    override fun equals(other: Any?): Boolean {
        return if (other === this) true
        else if (other !is DVector2) false
        else x == other.x && y == other.y
    }
    override fun hashCode() = x.hashCode() xor y.hashCode()
    override fun toString() = "($x,$y)"
}

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/772/B
    // 只用考虑相邻的两个边不会凹
    // 一开始想和中间的点的切点连线是角平分线，实际上公切线和 直线：前驱->后继 是平行的
    // 所以这个中间的点的切点的距离就等于三个点形成的三角形以 直线：前驱->后继 为底的高的一半
    // 求最小值即可
    val n = rd.ni()
    val points = ar(n) { DPoint2(rd.ni().toDouble(), rd.ni().toDouble()) }

    var ans = 1e9 * 2
    for (i in 0 until n) {
        val cur = points[i]
        val pre = if (i == 0) points.last() else points[i - 1]
        val nex = if (i == n - 1) points.first() else points[i + 1]

        val (toPre, toNex) = pre - cur to nex - cur
        val area = abs(toPre cross toNex)
        val distance = area / (nex - pre).len()
        ans = minOf(ans, distance / 2)
    }
    wt.printf("%.10f\n", ans)
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}