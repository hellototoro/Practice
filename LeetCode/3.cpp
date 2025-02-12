#include <iostream>
#include <string>
#include <unordered_set>
//a^b^c^b = a^c

int MinStr(void)
{
    char last_value;
    char CurrentValue;
    int res = 0;
    int left = 0, right = 0;
    int n = 100;
    char s[100];//"abcbbcbb"
    //LastValue = 
    for (int i{ 0 },value{ 0 }; i < n; ++i) {
        if (value ^ s[i] == value) {
            while (value ^ s[i] == last_value) {

            }
        }
        else {
            right++;
        }
        last_value = value;
        value ^= s[i];
        res = std::max(res, right - left);
   }
    return res;
}

int main()
{
    std::string s{"abcabcbb"};//awwkew
    std::unordered_set<char>table;
    int MaxLen = 0;
    int Left = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (table.find(s[i]) == table.end()) {
            table.insert(s[i]);
            MaxLen = std::max(MaxLen, i - Left + 1);
        }
        else {
            table.erase(s[Left++]);
        }



    }
}

