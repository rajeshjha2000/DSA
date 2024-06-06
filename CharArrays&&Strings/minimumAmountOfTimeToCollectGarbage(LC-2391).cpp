#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Initial pick time of M, P and G
        int pickM = 0, pickP = 0, pickG = 0;

        // Initial travel time of M, P and G
        int travelM = 0, travelP = 0, travelG = 0;

        // Count travel time from 0th index to lastM, lastP, lastG
        int lastM = 0, lastP = 0, lastG = 0;

        // Step 01: Calculate pick time and find travel time index 0th index to last index
        for (int i = 0; i < garbage.size(); i++) {
            string str = garbage[i];
            for (auto ch : str) {
                if (ch == 'M') {
                    pickM++;
                    lastM = i;
                }
                if (ch == 'P') {
                    pickP++;
                    lastP = i;
                }
                if (ch == 'G') {
                    pickG++;
                    lastG = i;
                }
            }
        }

        // Step 02: Calculate travel time from 0th index to last index
        for (int i = 0; i < lastP; i++) {
            travelP += travel[i];
        }
        for (int i = 0; i < lastM; i++) {
            travelM += travel[i];
        }
        for (int i = 0; i < lastG; i++) {
            travelG += travel[i];
        }

        // Step 03: Return sum of travel and pick time
        int finalAns = (pickM + travelM) + (pickP + travelP) + (pickG + travelG);
        return finalAns;
    }
};

int main() {
    Solution sol;

    vector<string> garbage1 = {"G", "P", "GP", "GG"};
    vector<int> travel1 = {2, 4, 3};
    cout << "Example 1: " << sol.garbageCollection(garbage1, travel1) << endl;  // Output: 21

    vector<string> garbage2 = {"MMM", "PGM", "GP"};
    vector<int> travel2 = {3, 10};
    cout << "Example 2: " << sol.garbageCollection(garbage2, travel2) << endl;  // Output: 37

    return 0;
}
