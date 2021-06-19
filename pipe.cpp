#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> price({0,0,2,4,5,9,7,6,10,6,10});


    for (int i = 1; i <= 10; ++i) {
        if(price.size() <= i) price.push_back(0);
        for (int j = 1; j <= i / 2; ++j) {
            price[i] = max(price[i], price[i - j] + price[j]);
        }
    }

    cout << price[10] + 2;
}