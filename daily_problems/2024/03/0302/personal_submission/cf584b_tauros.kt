class MInt(raw: Int) {
    companion object {
        val ZERO = MInt(0)
        val ONE = MInt(1)
    }
    val num = MOD.regular(raw)

    operator fun plus(other: Int): MInt = MInt(num ma other)
    operator fun minus(other: Int): MInt = MInt(num ms other)
    operator fun times(other: Int): MInt = MInt(num mm other)
    operator fun div(other: Int): MInt = MInt(num md other)

    operator fun plus(other: Long): MInt = MInt(num ma other)
    operator fun minus(other: Long): MInt = MInt(num ms other)
    operator fun times(other: Long): MInt = MInt(num mm other)
    operator fun div(other: Long): MInt = MInt(num md other)

    operator fun plus(other: MInt): MInt = MInt(num ma other.num)
    operator fun minus(other: MInt): MInt = MInt(num ms other.num)
    operator fun times(other: MInt): MInt = MInt(num mm other.num)
    operator fun div(other: MInt): MInt = MInt(num md other.num)

    fun pow(exp: Int) = MOD.pow(num.toLong(), exp.toLong()).toMInt()
    fun pow(exp: Long) = MOD.pow(num.toLong(), exp).toMInt()

    fun toInt(): Int {
        return num
    }

    override fun toString(): String {
        return num.toString()
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false
        other as MInt
        return num == other.num
    }

    override fun hashCode(): Int {
        return num
    }

    operator fun compareTo(other: MInt): Int = num.compareTo(other.num)
    operator fun compareTo(other: Int): Int = num.compareTo(other)
    operator fun compareTo(other: Long): Int = num.compareTo(other)
}
class MOD {
    companion object {
        private val INV_MAP = mutableMapOf<Int, MutableMap<Int, Int>>()
        private val INV_LONG_MAP = mutableMapOf<Int, MutableMap<Long, Int>>()
        var globalMod: Int = 0

        fun inv(num: Int): Int = INV_MAP.computeIfAbsent(globalMod) { mutableMapOf() }.computeIfAbsent(num) { inv(num, globalMod) }

        fun inv(num: Long): Int = INV_LONG_MAP.computeIfAbsent(globalMod) { mutableMapOf() }.computeIfAbsent(num) { inv(num, globalMod.toLong()).toInt() }

        fun pow(num: Long, p: Long): Int {
            var pow = p
            var a = num
            if (a >= globalMod) {
                a %= globalMod.toLong()
            }
            var res: Long = 1
            while (pow > 0) {
                if (pow and 1 == 1L) {
                    res = res * a % globalMod
                }
                a = a * a % globalMod
                pow = pow shr 1
            }
            return res.toInt()
        }

        inline fun regular(num: Int): Int = if (num in 0 until globalMod) num else {
            val r = num % globalMod
            r + (globalMod and (((r xor globalMod) and (r or -r)) shr 31))
        }

        inline fun regular(num: Long): Int = if (num in 0 until globalMod) num.toInt() else {
            val r = (num % globalMod).toInt()
            r + (globalMod and (((r xor globalMod) and (r or -r)) shr 31))
        }

        inline fun add(a: Int, b: Int): Int {
            val res = regular(a) + regular(b)
            return regular(res)
        }

        inline fun sub(a: Int, b: Int): Int {
            val res = regular(a) - regular(b)
            return regular(res)
        }

        inline fun mul(a: Int, b: Int): Int {
            val res = regular(a).toLong() * regular(b)
            return regular(res)
        }

        inline fun div(a: Int, b: Int): Int {
            val res = regular(a).toLong() * inv(regular(b))
            return regular(res)
        }

        inline fun <T> decorate(mod: Int, process: Companion.() -> T): T {
            globalMod = mod
            val res = process(Companion)
            globalMod = 0
            return res
        }
    }
}
fun exgcd(a: Int, b: Int): IntArray {
    // calc ax + by = gcd(a, b)
    // x = x0 + k * (b/gcd(a,b)); y = y0 - k * (a/gcd(a,b))
    // calc ax + by = o * gcd(a, b) -> calc a * o * x' + b * o * y' = o * gcd(a, b)
    // x = x0 * o + k * (b/gcd(a,b)); y = y0 * o - k * (a/gcd(a,b))
    if (b == 0) {
        // gcd, x, y
        return intArrayOf(a, 1, 0)
    }
    // x = y0; y = x0 - (a / b) * y0;
    val (gcd, x0, y0) = exgcd(b, a % b)
    val y = x0 - a / b * y0
    return intArrayOf(gcd, y0, y)
}
fun exgcd(a: Long, b: Long): LongArray {
    // calc ax + by = gcd(a, b)
    // x = x0 + k * (b/gcd(a,b)); y = y0 - k * (a/gcd(a,b))
    // calc ax + by = o * gcd(a, b) -> calc a * o * x' + b * o * y' = o * gcd(a, b)
    // x = x0 * o + k * (b/gcd(a,b)); y = y0 * o - k * (a/gcd(a,b))
    if (b == 0L) {
        // gcd, x, y
        return longArrayOf(a, 1, 0)
    }
    // x = y0; y = x0 - (a / b) * y0;
    val (gcd, x0, y0) = exgcd(b, a % b)
    val y = x0 - a / b * y0
    return longArrayOf(gcd, y0, y)
}
fun inv(a: Long, p: Long): Long {
    val (gcd, inv, _) = exgcd(a, p)
    if (gcd != 1L) return -1
    return (inv + p) % p
}
fun inv(a: Int, p: Int): Int {
    val (gcd, inv, _) = exgcd(a, p)
    if (gcd != 1) return -1
    return (inv + p) % p
}
infix fun Int.ma(other: Long): Int = MOD.add(this, MOD.regular(other))
infix fun Int.ma(other: Int): Int = MOD.add(this, other)
infix fun Int.md(other: Long): Int = MOD.div(this, MOD.regular(other))
infix fun Int.md(other: Int): Int = MOD.div(this, other)
typealias mint = MInt
infix fun Int.mm(other: Long): Int = MOD.mul(this, MOD.regular(other))
infix fun Int.mm(other: Int): Int = MOD.mul(this, other)
infix fun Int.ms(other: Long): Int = MOD.sub(this, MOD.regular(other))
infix fun Int.ms(other: Int): Int = MOD.sub(this, other)
fun Int.toMInt(): MInt = MInt(this)
inline fun <T> withMod(mod: Int, process: MOD.Companion.() -> T): T {
    return MOD.decorate(mod, process)
}

/**
 * generated by kotlincputil@tauros
 */
fun main(args: Array<String>) {
    // https://codeforces.com/problemset/problem/584/B
    // 排列组合，容斥一下，考虑 1 + 2 + 3 = 6 和 2 + 2 + 2 = 6 即可
    val n = readln().toInt()
    withMod(1e9.toInt() + 7) {
        val m3 = 3.toMInt()
        val single = m3.pow(3) - (3 * 2 * 1 + 1)
        var rest = 3 * n - 3
        var pre = mint.ONE
        var ans = mint.ZERO
        for (i in 0 until n) {
            val res = pre * single * m3.pow(rest)
            ans += res
            pre *= 3 * 2 * 1 + 1
            rest -= 3
        }
        println(ans)
    }
}