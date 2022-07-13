#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 + 10;
int n, m;
int a[N], s[N];

vector<int> alls;   // 存储原数轴上的值
vector<PII> add, query; // 存储操作数，请求数

int find(int x) {   // 二分查找原数轴上值的下标
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;   //映射到 1 ~ a.size()
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        alls.push_back(x);
        add.push_back({x, c});
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }

    // 排序 +　去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 进行加操作
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 计算前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i-1] + a[i];
    
    // 输出
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);

        cout << s[r] - s[l-1] << endl;
    }

    return 0;    
}