#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numOfInput;
    int target;
    vector<int> sequence;

    cin >> numOfInput >> target;

    for (int i = 0; i < numOfInput; ++i) {
        int tmp;
        cin >> tmp;
        sequence.push_back(tmp);
    }

    sequence.push_back(0);
    int minSize = INT32_MAX;
    int curTotal = 0;
    int headIndex = 0;
    int tailIndex = 0;

    while (headIndex < sequence.size()) {
        if (curTotal < target) {
            curTotal += sequence[headIndex++];
        } else {
            minSize = min(minSize, headIndex - tailIndex);
            curTotal -= sequence[tailIndex++];
        }
    }

    minSize = minSize == INT32_MAX ? 0 : minSize;
    cout << minSize;

}