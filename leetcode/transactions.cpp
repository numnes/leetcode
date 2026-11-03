#include <bits/stdc++.h>
#include <cstdlib>
#include <ranges>
#include <string_view>
using namespace std;

struct Transaction {
  string name;
  double amount;
  int time;
  string city;

  void print(){
    printf("%S\n %D\n %d\n %s\n", this->name, this->amount, this->time, this->city);
  }
};

class Solution {
public:
  Transaction splitS(string s) {
    auto range = s | std::ranges::views::split(',');
    vector<string> res;

    for (auto &&sub : range) {
      string_view token(sub.begin(), sub.end());
      string s(token);
      res.push_back(s);
    }

    Transaction t;
    t.name = res[0];
    t.amount = stoi(res[1]);
    t.time = stoi(res[2]);
    t.city = res[3];
    return t;
  }

  vector<string> invalidTransactions(vector<string> &transactions) {
    vector<string> invalid;
    map<string, Transaction> ptra;

    for (auto t : transactions) {
      Transaction a = this->splitS(t);
      cout << t << "\n";
      a.print();


    }
    return invalid;
  }
};

int main(void) {
  Solution s;
  vector<string> in = {"alice,20,800,mtv", "alice,50,1200,mtv"};

  for (auto c : s.invalidTransactions(in))
    cout << c << "\n";
}
