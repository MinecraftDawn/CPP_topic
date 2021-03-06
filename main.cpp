#include <iostream>

using namespace std;

// D = 當前FBT的深度(root深度定為1) (2 <= D <= 20)
// I = 第幾顆墜落的球 (1 <= I <= 524288)
void outputBallPos(int D, int I) {
    int pos = 1;
    // root深度為1，因而D減1
    D--;
    while (D) {
        // I 為偶數則pos往右；I 為奇數則pos往左
        if (I % 2) pos = pos << 1;
        else pos = (pos << 1) + 1;

        // 若I大於1，且I為偶數，則向右位移1格再加一 (可視為該子樹的N/2+1顆球)
        // 若I大於1，且I為奇數，則向右位移1格 (可視為該子樹的N/2顆球)
        // if(I > 1) I = I >> 1;
        if(I > 1) {
            if (I % 2) I = (I >> 1) + 1;
            else I = I >> 1;
        }

        D--;
    }
    cout << pos << endl;
}

int main() {
    // testcase = 總共有幾筆資料
    // D = 當前FBT的深度(root深度定為1) (2 <= D <= 20)
    // I = 第幾顆墜落的球 (1 <= I <= 524288)
    int testcase, D, I;
    cin >> testcase;
    for (int i = 0; i < testcase; ++i) {
        cin >> D >> I;
        outputBallPos(D, I);
    }
    // 把最後的-1讀取掉(無用到)
    cin >> testcase;

    return 0;
}