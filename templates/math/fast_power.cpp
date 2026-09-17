/*
 * 快速幂
 * Time: O(log n)  Space: O(1)
 *
 * 功能：
 *   - fast_pow：计算 a^n mod p
 *   - slow_mul：a*b mod p（防溢出，O(log b)）
 *   - mul：__int128 快速乘（编译器支持时更简洁）
 *
 * 关键步骤：
 *   - n & 1 时累乘
 *   - a 自乘取模
 *
 * 编译：g++ -std=c++17 -O2 -o fast_power fast_power.cpp
 */

#include <iostream>
using namespace std;
typedef long long ll;

ll fast_pow(ll a, ll n, ll p) {
    ll res = 1;
    a = (a % p + p) % p;
    while (n > 0) {
        if (n & 1) res = res * a % p;  // 奇数次幂，累乘
        a = a * a % p;
        n >>= 1;
    }
    return res;
}

ll slow_mul(ll a, ll b, ll p) {
    ll res = 0;
    a = (a % p + p) % p;
    while (b > 0) {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

ll mul(ll a, ll b, ll p) {
    return (__int128)a * b % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, n, p;
    cin >> a >> n >> p;
    cout << fast_pow(a, n, p) << "\n";
    return 0;
}
