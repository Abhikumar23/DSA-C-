#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> temp;
    int n = intervals.size();

    for (int i = 0; i < n; i++) {
        if (intervals[i][1] < newInterval[0]) {  // No overlap, push as is
            temp.push_back(intervals[i]);
        } 
        else if (intervals[i][0] > newInterval[1]) {  // Insert newInterval and update
            temp.push_back(newInterval);
            newInterval = intervals[i];  // Now, treat intervals[i] as newInterval
        } 
        else {  // Overlapping intervals, merge them
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    temp.push_back(newInterval);  // Push the last interval
    return temp;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insert(intervals, newInterval);

    // Printing the result
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
