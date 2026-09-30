#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nums = 5;
    int sum = 0;
    int* p = new int(nums);
    for (int i = 0; i < nums; i++)
    {
        cin >> nums[p];

        sum += nums[p];
    }
    cout << sum;

    delete[] p;
}