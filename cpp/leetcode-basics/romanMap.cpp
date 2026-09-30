#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int prevValue = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int curValue = romanMap[s[i]];

            if (curValue >= prevValue) {
                result += curValue;
            }
            else {
                result -= curValue;
            }

            prevValue = curValue;
        }

        return result;
    }
};

int main1() {
    setlocale(LC_ALL, "rus");

    Solution solution;
    string s = "MIMXCIL"; // Пример римского числа

    int result = solution.romanToInt(s);
    cout << "Результат: " << result << endl;

    return 0;
}