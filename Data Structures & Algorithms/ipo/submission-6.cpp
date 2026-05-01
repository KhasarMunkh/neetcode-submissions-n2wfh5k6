class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minHeap;
        priority_queue<int> maxProfitsHeap;
        for (int i = 0; i < profits.size(); i++) {
            minHeap.push({capital[i],profits[i]});
        }
        // k times, do a project
        for (int i = 0; i < k; i++) {
            // collect the projects we can do with our current capital
            // and push the profits into a maxHeap
            while (!minHeap.empty()&& w >= minHeap.top().first) {
                int profit = minHeap.top().second;
                minHeap.pop();
                maxProfitsHeap.push(profit);
            }
            if (maxProfitsHeap.empty()) {
                return w;
            }
            w += maxProfitsHeap.top();
            maxProfitsHeap.pop();
        }
        return w;
    }
};
