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

    int curTotal = 0;
    int headIndex = 0;
    int tailIndex = 0;
    int minLength = INT32_MAX;

    while (headIndex < sequence.size()) {
        if (curTotal < target) {
            curTotal += sequence[headIndex++];
        } else {
            minLength = min(minLength, headIndex - tailIndex);
            curTotal -= sequence[tailIndex++];
        }
    }

    cout << (minLength != INT32_MAX ? minLength : 0);
}