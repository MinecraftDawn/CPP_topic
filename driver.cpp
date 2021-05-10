#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 當測資尚未結束時
    while (!cin.eof()) {
        /*
         * n: 司機數量
         * d: 上限里程
         * r: 超越上限里程的單位里程成本
         * cost: 超越上限里程的成本總額
         */
        int n, d, r;
        int cost = 0;

        // 早上路線距離
        vector<int> moring;

        // 傍晚路線距離
        vector<int> evening;

        cin >> n >> d >> r;

        // 測資全0時，代表測資結束
        if (n == 0 && d == 0 && r == 0) break;

        // 輸入早上的路線距離
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            moring.push_back(input);
        }

        // 輸入傍晚的路線距離
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            evening.push_back(input);
        }

        // 早上的路線，依照升冪排序
        sort(moring.begin(), moring.end());
        // 傍晚的路線，依照降冪排序
        sort(evening.begin(), evening.end(), greater<int>());

        // 計算超出的里程
        for (int i = 0; i < n; i++) {
            int meter = moring[i] + evening[i];
            if (meter > d) cost += meter - d;
        }

        // 輸出超出李成的價格
        cout << cost * r << endl;
    }

}