/*
 * 二分查找模板
 * 算法：整数二分
 * 时间复杂度：O(log n)
 * 空间复杂度：O(1)
 *
 * 功能：
 *   - lower_bound: 在有序数组中找第一个 >= x 的位置
 *   - upper_bound: 在有序数组中找第一个 >  x 的位置
 *   - binary_search: 判断 x 是否存在
 *
 * 编译：g++ -std=c++17 -O2 -o binary_search binary_search.cpp
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int a[MAXN];

// 第一个 >= x 的下标，不存在返回 n
int my_lower_bound(int a[], int n, int x) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// 第一个 > x 的下标，不存在返回 n
int my_upper_bound(int a[], int n, int x) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    while (m--) {
        int x;
        cin >> x;

        // 方法一：手写二分
        int pos = my_lower_bound(a, n, x);
        // 方法二：STL
        // int pos = lower_bound(a, a + n, x) - a;

        if (pos < n && a[pos] == x) {
            cout << x << " 存在，第一个位置: " << pos << "\n";
            // x 的出现次数 = upper_bound - lower_bound
            int cnt = my_upper_bound(a, n, x) - pos;
            cout << "出现次数: " << cnt << "\n";
        } else {
            cout << x << " 不存在\n";
        }
    }

    return 0;
}
