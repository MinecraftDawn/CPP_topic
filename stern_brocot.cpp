#include <iostream>

using namespace std;

// 儲存分子與分母的class
class Number {
private:
    int numeratpor;
    int denominator;

public:
    Number(int numerator, int denominator) {
        this->numeratpor = numerator;
        this->denominator = denominator;
    }

    // 取得分子除分母計算出來的值
    double getValue() {
        return (double) numeratpor / denominator;
    }

    // 用另一個物件，直接複寫分子分母的值
    void setValue(Number *num) {
        this->numeratpor = num->numeratpor;
        this->denominator = num->denominator;
    }

    // 用另一個物件，把分子分母的值相加後儲存
    void addValue(Number *num) {
        this->numeratpor += num->numeratpor;
        this->denominator += num->denominator;
    }

    // getter of Numeratpor
    int getNumeratpor() {
        return this->numeratpor;
    }

    // getter of Denominator
    int getDenominator() {
        return this->denominator;
    }

    bool operator==(Number num) {
        if (this->getNumeratpor() == num.getNumeratpor() && this->getDenominator() == num.getDenominator()) {
            return true;
        } else {
            return false;
        }
    }

    bool operator!=(Number num) {
        return !(*this == num);
    }
};


int main() {
    // 設定目標的分子分母變數
    int target_numerator, target_denominator;

    while (!cin.eof()) {
        // 訂定左、中、右三個物件 (題目只需要用三個物件即可)
        Number *left = new Number(0, 1);
        Number *mid = new Number(1, 1);
        Number *right = new Number(1, 0);

        // 一次讀取兩個值，分別為分子和分母
        cin >> target_numerator;
        cin >> target_denominator;

        // 設定目標的物件
        Number *target = new Number(target_numerator, target_denominator);
        // 若target和mid的物件值不相同則繼續迴圈
        while (*mid != *target) {
            if (mid->getValue() < target->getValue()) {
                left->setValue(mid);
                mid->addValue(right);
                cout << "R";
            } else {
                right->setValue(mid);
                mid->addValue(left);
                cout << "L";
            }
        }
        cout << endl;
    }
}