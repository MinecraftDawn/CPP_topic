#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // �����|��������
    while (!cin.eof()) {
        /*
         * n: �q���ƶq
         * d: �W�����{
         * r: �W�V�W�����{����쨽�{����
         * cost: �W�V�W�����{�������`�B
         */
        int n, d, r;
        int cost = 0;

        // ���W���u�Z��
        vector<int> moring;

        // �ı߸��u�Z��
        vector<int> evening;

        cin >> n >> d >> r;

        // �����0�ɡA�N����굲��
        if (n == 0 && d == 0 && r == 0) break;

        // ��J���W�����u�Z��
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            moring.push_back(input);
        }

        // ��J�ıߪ����u�Z��
        for (int i = 0; i < n; ++i) {
            int input;
            cin >> input;
            evening.push_back(input);
        }

        // ���W�����u�A�̷Ӥɾ��Ƨ�
        sort(moring.begin(), moring.end());
        // �ıߪ����u�A�̷ӭ����Ƨ�
        sort(evening.begin(), evening.end(), greater<int>());

        // �p��W�X�����{
        for (int i = 0; i < n; i++) {
            int meter = moring[i] + evening[i];
            if (meter > d) cost += meter - d;
        }

        // ��X�W�X����������
        cout << cost * r << endl;
    }

}