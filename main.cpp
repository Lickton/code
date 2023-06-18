#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <algorithm>

int main()
{
  int q[] = {4, 3, 5, 1, 2};

  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      if (q[i] > q[j]) std::swap(q[i], q[j]);
    }
  }

  for (auto x : q) {
    printf("%d ", x);
  }

  puts("");
  
  return 0;
}
