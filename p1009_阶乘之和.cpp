#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 用于存储和计算超大整数的类
 */
class BigInt {
private:
    vector<int> num;//存储数字，低位在前，例如1234->[4，3，2，1]
    /**
     * @brief 移除前导零
     */
    void trimLeadingZeros() {
        while (num.size() > 1 && num.back() == 0) {
            num.pop_back();
        }
    }

public:
    /**
     * @brief 默认构造函数，初始化为0
     */
    BigInt() : num(1, 0) {
        
    }

    /**
     * @brief 从int构造
     */
    BigInt(int x) {
        if (x == 0) {
            num.assign(1, 0);
            return;
        }
        while (x > 0) {
            num.push_back(x % 10);
            x /= 10;
        }
    }
    /**
     *@brief 高精度加法
     */
    BigInt operator+(const BigInt& b) const {
        BigInt result;
        result.num.clear();

        int carry = 0;
        size_t max_size = max(this->num.size(), b.num.size());

        for (size_t i = 0; i < max_size || carry; i++) {
            int digit_a = (i < this->num.size()) ? this->num[i] : 0;
            int digit_b = (i < b.num.size()) ? b.num[i] : 0;

            int sum = digit_a + digit_b + carry;
            result.num.push_back(sum % 10);
            carry = sum / 10;
        }
        result.trimLeadingZeros();
        return result;
    }

    /**
     *@brief 高精度乘法 (BigInt * int)
     */
    BigInt operator*(int b) const {
        BigInt result;
        result.num.clear();

        long long carry = 0;
        for (size_t i = 0; i < this->num.size() || carry; i++) {
            long long product = carry;
            if (i < this->num.size()) {
                product += static_cast<long long>(this->num[i]) * b;
            }

            result.num.push_back(product % 10);
            carry = product / 10;
        }
        result.trimLeadingZeros();
        return result;
    }

    /**
     *@brief 将BigInt转换为字符串输出
     */
    string toString() const {
        string s;
        for (int i = num.size() - 1; i >= 0; i--) {
            s += (num[i] + '0');
        }
        return s;
    }
    
};

int main() {
    int n;
    cin >> n;

    BigInt sum;
    BigInt factorial(1);

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            factorial = factorial * i;
        }
        sum = sum + factorial;
    }

    cout << sum.toString() << endl;
    
    return 0;
}