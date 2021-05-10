#include <iostream>

using namespace std;

// �x�s���l�P������class
class Number {
private:
    int numeratpor;
    int denominator;

public:
    Number(int numerator, int denominator) {
        this->numeratpor = numerator;
        this->denominator = denominator;
    }

    // ���o���l�������p��X�Ӫ���
    double getValue() {
        return (double) numeratpor / denominator;
    }

    // �Υt�@�Ӫ���A�����Ƽg���l��������
    void setValue(Number *num) {
        this->numeratpor = num->numeratpor;
        this->denominator = num->denominator;
    }

    // �Υt�@�Ӫ���A����l�������Ȭۥ[���x�s
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
    // �]�w�ؼЪ����l�����ܼ�
    int target_numerator, target_denominator;

    while (!cin.eof()) {
        // �q�w���B���B�k�T�Ӫ��� (�D�إu�ݭn�ΤT�Ӫ���Y�i)
        Number *left = new Number(0, 1);
        Number *mid = new Number(1, 1);
        Number *right = new Number(1, 0);

        // �@��Ū����ӭȡA���O�����l�M����
        cin >> target_numerator;
        cin >> target_denominator;

        // �]�w�ؼЪ�����
        Number *target = new Number(target_numerator, target_denominator);
        // �Ytarget�Mmid������Ȥ��ۦP�h�~��j��
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