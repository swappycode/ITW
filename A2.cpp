#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap(piles.begin(), piles.end());
    while (k--) {
        int top = maxHeap.top();
        maxHeap.pop();
        top -= top / 2; // Remove floor(top / 2) stones
        maxHeap.push(top); // Push the reduced pile back
    }
    int totalStones = 0;
    while (!maxHeap.empty()) {
        totalStones += maxHeap.top();
        maxHeap.pop();
    }
    return totalStones;
}

int main() {
    vector<int> piles1 = {5, 4, 9};
    int k1 = 2;
    cout << "Example 1 Output: " << minStoneSum(piles1, k1) << endl;

    vector<int> piles2 = {4, 3, 6, 7};
    int k2 = 3;
    cout << "Example 2 Output: " << minStoneSum(piles2, k2) << endl;

    return 0;
}
