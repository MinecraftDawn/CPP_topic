#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int length;
    vector<int> price({0});

    cin >> length;
    while(!cin.eof()){
        int p;
        cin >> p;
        if(p == 0) break;
        cin >> p;
        price.push_back(p);
    }

    for (int i = 1; i <= length; ++i) {
        if(price.size() <= i) price.push_back(0);
        for (int j = 1; j <= i / 2; ++j) {
            price[i] = max(price[i], price[i - j] + price[j]);
        }
    }

    cout << price[length];
}