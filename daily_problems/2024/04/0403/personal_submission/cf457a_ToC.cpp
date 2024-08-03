/*
问题：
    1、为什么不能像十进制、二进制一样比较大小？
        高位的权重不够大
    2、比较大小的常用手段有什么? 
        做差和做商
    3、q^2 = q + 1有什么作用? 
        用来降幂，且降幂的digit变为0
思路：
    1、把两个字符串做差，得diff
    2、diff降幂到只有两个digit
    3、比较diff与0

问题：
    4、数字的权重表示法的适用范围？
        对于数位（digit）是负数也适用

    5、降幂过程中digit很大，存不下怎么办？
    最高位等于1低位全0的数，不足以比 最高位等于0低位全1的数 更大
    那么取更大的digit呢？
    发现：
        2q^k > q^(k-1) + q^(k-2) + ... + q + 1
    所以降幂过程中，首次出现digit >= 2 || digit <= -2时，
    因为前面全是0，所以可以直接知道差diff的正负
*/
string s1, s2;
double dig[N];
void sol()
{
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();
    int len = max(l1, l2);
    
    if (len == 1) {
        cout << (s1 == s2 ? "=\n" : (s1 < s2 ? "<\n" : ">\n"));
        return ;
    }

    if (len > l1) s1 = string(len - l1, '0') + s1;
    if (len > l2) s2 = string(len - l2, '0') + s2;
    // cout << s1 << '\n' << s2 <<'\n';
    for (int i = 0; i < len; i++) {
        if (s1[i] == '1') dig[i]++;
        if (s2[i] == '1') dig[i]--;        
        if (i < len - 2) {
            dig[i + 1] += dig[i];
            dig[i + 2] += dig[i];
            // dig[i] = 0;
        }
    }
    
    if (dig[len - 1] == 0 && dig[len - 2] == 0) {
        cout << "=\n";
    } else {
        double res = dig[len - 2] * (sqrt(5.0) + 1) / 2.0 + dig[len - 1];
        cout << (res < 0 ? "<\n" : ">\n");
        return ;
    }
}
