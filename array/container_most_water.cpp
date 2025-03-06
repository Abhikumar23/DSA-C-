#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0;
    int start = 0;
    int end = height.size() - 1;

    while (start < end) {
        int vol = end - start;
        int heigh = min(height[start], height[end]);
        int area = vol * heigh;
        max_area = max(max_area, area);

        if (height[start] < height[end]) {
            start++;
        } else {
            end--;
        }
    }

    return max_area;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};  // Example input
    cout << "Maximum Area: " << maxArea(height) << endl;
    return 0;
}
