#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // Ū����J���
    string str;
    getline(cin, str);
    vector<char> row(str.begin(),str.end());
    getline(cin, str);
    vector<char> col(str.begin(),str.end());

    // ��l��dp�ܼ�
    vector<vector<int>> dp(col.size() + 1, vector<int>(row.size() + 1, 0));

    for (int r = 0; r < col.size(); ++r) {
        for (int c = 0; c < row.size(); ++c) {
            // �Y�۵��A�h�����W���Ʀr�[�@
            if (row[c] == col[r]) {
                dp[r + 1][c + 1] = dp[r][c] + 1;
            // �Y���۵��A�����B�W�̤j��
            } else {
                dp[r + 1][c + 1] = max(dp[r + 1][c], dp[r][c + 1]);
            }
        }
    }

    cout << dp[col.size()][row.size()] << endl;
}