#include<iostream>
using namespace std;

string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true) {
        int index = k / fact;
        ans = ans + to_string(numbers[index]);
        numbers.erase(numbers.begin() + index);

        if (numbers.size() == 0) {
            break;
        }
        
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

