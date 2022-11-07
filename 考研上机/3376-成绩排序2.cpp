#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
struct Person{
    int id;
    int score;
    
    bool operator< (const Person& t) const {
        if (score != t.score) return score < t.score;
        else return id < t.id;
    }
}q[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].id >> q[i].score;
    sort(q, q+n);
    for (int i = 0; i < n; i++)
        cout << q[i].id << ' ' << q[i].score << endl;
    
    return 0;
}