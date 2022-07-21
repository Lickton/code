#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef pair<LL, PII> PDD;
const int N = 10010;

LL n, res = 0;
vector<PDD> col, row;

vector<PII> merge(vector<PII> &segs)
{
    vector<PII> tmp;
    LL st = -2e9, ed = -2e9;
    sort(segs.begin(), segs.end());

    for (auto seg : segs) {
        if (ed < seg.first) {
            if (ed != -2e9) tmp.push_back({st, ed});
            st = seg.first, ed = seg.second;
        } else 
            ed = max(seg.second, ed);
    }

    if (st != -2e9)
        tmp.push_back({st, ed});

    return tmp;
}

int check(PDD eachcol) {
    LL count = 0;
    for (auto seg : row) {
        if (eachcol.first >= seg.second.first && eachcol.first <= seg.second.second)
            if (seg.first >= eachcol.second.first && seg.first <= eachcol.second.second)
                count++;
    }
    // cout << count << endl;
    return count;
}

void merge_sort(vector<PDD> &col, int flag)
{
    vector<PDD> tmp;
    vector<PII> samerow;
    sort(col.begin(), col.end());
    LL rownum = col[0].first;
    for (auto seg : col) {
        if (rownum != seg.first) {
            samerow = merge(samerow);
            for (auto each : samerow)
                tmp.push_back({rownum, each});
            samerow.clear();
            rownum = seg.first;
        }
        samerow.push_back(seg.second);
    }


    samerow = merge(samerow);
    for (auto each : samerow)
        tmp.push_back({rownum, each});

    col = tmp;

    for (auto seg : col) 
        res += seg.second.second - seg.second.first + 1;

    if (flag)
        for (auto eachcol : col)
            res -= check(eachcol);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) row.push_back({y1, {min(x1,x2), max(x1,x2)}});
        else col.push_back({x1, {min(y1,y2), max(y1,y2)}});
    }

    merge_sort(row, 0);
    // for (auto each : row)
    //     cout << "colnum:" << each.first << " " << "X1:" << each.second.first << " " << "X2:" << each.second.second << endl;
    merge_sort(col, 1);
    // for (auto each : col)
    //     cout << "rownum:" << each.first << " " << "Y1:" << each.second.first << " " << "Y2:" << each.second.second << endl;
    
    cout << res << endl;

    return 0;
}