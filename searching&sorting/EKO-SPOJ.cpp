#include <iostream>
#include <vector>
#include <algorithm>

bool isWoodSufficient(const std::vector<int>& trees, int m, int cutHeight) {
    long long woodCollected = 0;
    for(int height : trees) {
        if(height > cutHeight) {
            woodCollected += (height - cutHeight);
        }
    }
    return woodCollected >= m;
}

int findMaxCutHeight(const std::vector<int>& trees, int m) {
    int left = 0;
    int right = *max_element(trees.begin(), trees.end());
    int maxCutHeight = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(isWoodSufficient(trees, m, mid)) {
            maxCutHeight = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxCutHeight;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> trees(n);
    for(int i = 0; i < n; i++) {
        std::cin >> trees[i];
    }

    int result = findMaxCutHeight(trees, m);
    std::cout << result << std::endl;

    return 0;
}
