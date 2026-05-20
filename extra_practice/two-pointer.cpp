#include <iostream>
#include <string.h>

using namespace std;

class Solution {
    public:
        void swap(char* a, char* b) {
            char tmp = *a;
            *a = *b;
            *b = tmp;
        }

        string reverseWords(string s) {
            int start = 0;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ' || i == s.length() - 1) {
                    int end = (i == s.length() - 1 && s[i] != ' ') ? i + 1 : i;
                    while (start < end) {
                        swap(&s[start], &s[end - 1]);
                        start++;
                        end--;
                    }
                    start = i + 1;
                }
            }

            return s;
        }
};

int main() {

    Solution* answ = new Solution;
    cout << answ->reverseWords("Let's take LeetCode contest");

    return 0;
}