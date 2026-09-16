/*
 * 快速幂模板
 * 时间复杂度：O(log n)
 * 空间复杂度：O(1)
 *
 * 功能：
 *   - 快速幂：计算 a^n mod p
 *   - 龟速乘：防止 a * b 溢出（a*b mod p，O(log b)）
 *
 * 编译：g++ -std=c++17 -O2 -o fast_power fast_power.cpp
 */

#include <iostream>
using namespace std;

typedef long long ll;

// 快速幂：计算 a^n mod p
ll fast_pow(ll a, ll n, ll p) {
    ll res = 1;
    a = (a % p + p) % p;  // 处理负数
    while (n > 0) {
        if (n & 1) res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}

// 龟速乘：计算 a * b mod p，防止溢出（O(log b)）
// 当 a, b 达到 1e18 时，直接 a * b 会溢出 long long
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

// __int128 快速乘（当编译器支持时，更简单）
ll mul(ll a, ll b, ll p) {
    return (__int128)a * b % p;
}

// 矩阵快速幂示例（2x2矩阵）
struct Matrix {
    ll a[2][2];
    Matrix() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
};

Matrix matrix_mul(const Matrix &A, const Matrix &B, ll p) {
    Matrix C;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % p;
    return C;
}

Matrix matrix_pow(Matrix A, ll n, ll p) {
    Matrix res;  // 单位矩阵
    res.a[0][0] = res.a[1][1] = 1;
    while (n > 0) {
        if (n & 1) res = matrix_mul(res, A, p);
        A = matrix_mul(A, A, p);
        n >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, n, p;
    cin >> a >> n >> p;

    cout << fast_pow(a, n, p) << "\n";

    // 示例：用矩阵快速幂求斐波那契第 n 项 mod p
    // [F(n+1)]   [1 1]^n   [1]
    // [F(n)  ] = [1 0]   * [0]
    // 见 notes/math/ 目录下的斐波那契笔记

    return 0;
}
