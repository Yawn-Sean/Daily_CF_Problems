private fun goldenSystem(s1: String, s2: String): String {
    if (s1 == s2) {
        return "="
    }
    val n1 = s1.length
    val n2 = s2.length
    val n = max(n1, n2)
    val nums1 = (IntArray(max(n2 - n1, 0)).toList() + s1.map { it.toDigit() }).toIntArray()
    val nums2 = (IntArray(max(n1 - n2, 0)).toList() + s2.map { it.toDigit() }).toIntArray()
    for (i in 0 until n) {
        if (nums1[i] == nums2[i]) {
            continue
        }
        val diff = abs(nums1[i] - nums2[i])
        if (nums1[i] > nums2[i]) {
            if (diff > 1 || i + 2 >= n) {
                return ">"
            }
            nums1[i + 1] += diff
            nums1[i + 2] += diff
        } else {
            if (diff > 1 || i + 2 >= n) {
                return "<"
            }
            nums2[i + 1] += diff
            nums2[i + 2] += diff
        }
    }
    return "="
}
