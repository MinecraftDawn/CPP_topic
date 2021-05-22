#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int size;
    vector<vector<int>> items;

    cin >> size;
    while(!cin.eof()){

        int v1,v2,v3;
        cin >> v1 >> v2 >> v3;
        if (v1 == -1) break;

        vector<int> tmp({v1,v2,v3});
        items.push_back(tmp);
    }

    vector<vector<vector<int>>> dp(items.size() + 1, vector<vector<int>>(size + 1, vector<int>(2, 0)));

    for (int i = 0; i < items.size(); ++i) {
        for (int j = 0; j <= size; ++j) {
            int weight = items[i][1];
            int price = items[i][2];
            if (weight > j) {
                dp[i + 1][j][0] = dp[i][j][0];
            } else {
                dp[i+1][j][0] = max(dp[i][j][0], dp[i][j-weight][0]+ price);
                if(dp[i][j-weight][0] + price > dp[i][j][0]){
                    dp[i][j][1] = 1;
                }
            }
        }
    }

    for (int i = items.size(), j = size; i >= 0; --i) {
        if (dp[i][j][1]) {
            cout << items[i][0] << " ";
            j -= items[i][1];
        }
    }

    cout << endl << dp[items.size()][size][0] << endl;

}