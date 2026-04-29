class MedianFinder {

    std::priority_queue<int, std::vector<int>> small; // MaxHeap for 1st half of vals
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        large; // MinHeap for 2nd half of vals

  public:
    MedianFinder() {}

    void addNum(int num) {
        // arbitrarily push to small(MaxHeap)
        // then swap with large(minHeap) if necessary
        small.push(num);
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        // handle uneven size (lengths differ by more than 1)
        // 1. small length > large length + 1;
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        // 2. small length + 1 < large length;
        if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return (double)small.top();
        } else if (large.size() > small.size()) {
            return (double)large.top();
        } else {
            return (double)((small.top() + large.top()) / 2.0);
        }
    }
};
