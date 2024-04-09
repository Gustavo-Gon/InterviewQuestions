/*
 * There is a small, one-way bridge that can carry a maximum weight of U units at a time.
 * There is also a line of N cars waiting to cross the bridge.
 * The weights of the cars are given as an array weight.
 * The weight of the K-th car in the line is weight [K] (for K within the range [ON-1]).
 * The car that will enter the bridge first weighs weight [0], the car that will enter second weighs weight [1], and so on.
 * At most two cars can be on the bridge at the same time.
 * To begin, the first two cars in line will enter the bridge.
 * Then the third car will enter the bridge as soon as the first car leaves the bridge, the fourth car will enter when the second car leaves, and so on.
 * The cars leave the bridge in the same order they entered it.
 * However, this may lead to a situation where cars exceed the bridge's weight limit.
 * To prevent such a situation, some drivers have to turn back.
 * When a driver turns back, all drivers behind them in line move one position closer to the bridge.
 * The driver who turns back is removed from the line and will not try to cross the bridge again.
 * Your task is to find the minimum number of drivers that must turn back so that the bridge will not be overloaded.
 *
Write a function:
 class Solution ( public int solution(int U, int[] weight); }

that, given an integer U representing the weight limit of the bridge and an array weight of N integers representing the weights of the cars in line,
returns the minimum number of drivers that must turn back so that the bridge will not be overloaded.
 *
 */
#include <vector>
#include <iostream>

using namespace std;

vector<int> filterWeights(int U, const vector<int> &weight) {
    vector<int> validWeights;

    for (int w : weight) {
        if (w <= U) {
            validWeights.push_back(w); // Adds the car to the new array if it's less than or equal to U
        }
    }

    return validWeights;
}

int solution(int U, const vector<int> &validWeights) {
    if (validWeights.empty()) return 0; // If no car is lighter than U, none can pass

    vector<int> bridge; // An array the represents the bridge
    int passed = 0;

    for (int c : validWeights) {
        bridge.push_back(c); // Add the car to the bridge

        if (bridge.size() == 2) {
            if (bridge[0] + bridge[1] > U) { // Checks to if both cars don't exceed U
                bridge.pop_back(); // Remove the last car to enter the bridge
            }
            else {
                passed++;
                bridge.erase(bridge.begin()); // Remove first car to pass
            }
        }
    }

    if (!bridge.empty()) { //If only one car is left it passes
        passed++;
    }
    return passed;
}

int main() {
    vector<int> weight = {5, 18, 3, 12}; // Example weights
    int U = 10; // Maximum allowable combined weight on the bridge
    vector<int> validWeights = filterWeights(U, weight);
    int passed = solution(U, validWeights); // Calculate how many cars pass based on valid weights
    cout << "Number of cars passed: " << passed << endl;
    return 0;
}