#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> lastPos(200,-1);
    int begin = 0;
    int bigger = 0;

    for(int end = 0; end < s.length(); end++){
      char c = s[end];

      if(lastPos[c] >= begin){
        begin = lastPos[c] +1;
      }

      lastPos[c] = end;

      int size = end - begin +1;
      bigger = max(size, bigger);
    }

    return bigger;
  }
};

int main(void) {
  string st = "dbcdfeecafeeccebebeebedaaefbdbfebadcbfceadeedebebbaaabfecfdcbcfdfdcbbefdecfddedacebacdaeabaeebdeacffbbaefbdcaeacafdeacbdafcdbfcbdeccfabfcfbfadafadfeabfcfdcafdfadcffcefaecdbdbdcbeebcfebddbffcbecbfeeddfaeaeabbfbfdeacdaddcdbdadebccadcdfedfdbbfefeaadbdefedcbcbffbefb";
  Solution s;
  cout << s.lengthOfLongestSubstring(st) << "\n";
}
