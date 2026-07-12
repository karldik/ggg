#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int minOperations(int x, int y) {
    if (x == y) return 0;

    queue<int> q;
    unordered_set<int> visited;

    q.push(x);
    visited.insert(x);

    int steps = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();

            if (cur == y) return steps;

            vector<int> nextStates;

            // Операции
            nextStates.push_back(cur - 1);
            nextStates.push_back(cur + 1);

            if (cur % 11 == 0) {
                nextStates.push_back(cur / 11);
            }

            if (cur % 5 == 0) {
                nextStates.push_back(cur / 5);
            }

            for (int nxt : nextStates) {
                if (nxt >= 0 && visited.find(nxt) == visited.end()) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        steps++;
    }

    return -1;
}

int main() {
    cout << minOperations(52, 1) << endl;  // 55/11 = 5; 5/5 = 1 (2 операции)
    cout << minOperations(10, 2) << endl;  // 10/5 = 2 (1 операция)
    cout << minOperations(7, 32) << endl;   // 7-1-1-1-1 = 3 (4 операции)
    return 0;
}