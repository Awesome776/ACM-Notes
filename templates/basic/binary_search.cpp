/*
 * 二分查找
 * Time: O(log n)  Space: O(1)
 *
 * 功能：
 *   - lower_bound：有序数组中第一个 >= x 的下标
 *   - upper_bound：有序数组中第一个 >  x 的下标
 *   - 存在性判断 + 出现次数
 *
 * 编译：g++ -std=c++17 -O2 -o binary_search binary_search.cpp
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int a[MAXN];

int lower_bound(int a[], int n, int x) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int upper_bound(int a[], int n, int x) {
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
        int pos = lower_bound(a, n, x);
        if (pos < n && a[pos] == x) {
            int cnt = upper_bound(a, n, x) - pos;  // 出现次数
            cout << pos << " " << cnt << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
