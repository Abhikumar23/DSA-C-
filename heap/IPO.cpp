#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Min-heap to store projects sorted by required capital
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minCapital;
        
        // Max-heap to store feasible projects sorted by profit
        priority_queue<int> maxProfit;
        
        // Push all projects into the min-heap by capital requirement
        for (int i = 0; i < n; ++i) {
            minCapital.push({capital[i], profits[i]});
        }
        
        // Perform up to k selections
        for (int i = 0; i < k; ++i) {

            // Move all feasible projects into max-heap based on available capital
            while (!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }
            
            // If no projects can be started, stop
            if (maxProfit.empty()) {
                break;
            }
            
            // Pick the most profitable project
            w += maxProfit.top();
            maxProfit.pop();
        }
        
        return w;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    int k = 2, w = 0;
    
    int maxCapital = sol.findMaximizedCapital(k, w, profits, capital);
    cout << "Maximum Capital: " << maxCapital << endl;
    
    return 0;
}
