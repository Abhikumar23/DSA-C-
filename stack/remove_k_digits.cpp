#include <iostream>
#include <string>
using namespace std;

string removeKDigits(string num, int k) {
    string result;
    
    for (char digit : num) {
        while (!result.empty() && k > 0 && result.back() > digit) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }
    
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }
    
    int i = 0;
    while (i < result.size() && result[i] == '0') {
        i++;
    }
    
    string finalResult = result.substr(i);
    
    return finalResult.empty() ? "0" : finalResult;
}

int main() {
    string num;
    int k;
    
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the number of digits to remove: ";
    cin >> k;
    
    string smallestNumber = removeKDigits(num, k);
    cout << "Smallest possible number: " << smallestNumber << endl;
    
    return 0;
}