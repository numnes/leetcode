#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> values;
    vector<int> result;

    for (auto n : nums) {
      if (values.find(n) != values.end()) {
        values[n] = values[n] += 1;
        continue;
      }

      values[n] = 1;
    }

    vector<pair<int, int>> Vvalues(values.begin(), values.end());

    sort(Vvalues.begin(), Vvalues.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second < b.second;
         });

    for (int i = 0; i < k; i++) {
      result.push_back(Vvalues.back().first);
      Vvalues.pop_back();
    }

    return result;
  }
};

int main(void) {
  vector<int> input = {1, 1, 1, 2, 2, 3};
  int k = 2;

  Solution s;

  vector<int> result = s.topKFrequent(input, k);

  for (auto n : result)
    cout << n << ", ";
  cout << "\n";
}
