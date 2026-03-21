#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || c + b <= a) {
        cout << "Not triangle" << endl;
        return 0;
    } else {
        long long a1 = (long long) (a * a);
        long long b1 = (long long) (b * b);
        long long c1 = (long long) (c * c);
        int max_side = max({a, b, c});
        long long max_sq;
        if (max_side == a) {
            max_sq = a1;
        } else if (max_side == b) {
            max_sq = b1;
        } else {
            max_sq = c1;
        }
        long long sum_other = a1 + b1 + c1 - max_sq;
        if (sum_other == max_sq) {
            cout << "Right triangle" << endl;
        } else if (sum_other > max_sq) {
            cout << "Acute triangle" << endl;
        } else if (sum_other < max_sq){
            cout << "Obtuse triangle" << endl;
        }

        if (a == b || b == c || c == a) {
            cout << "Isosceles triangle" << endl;
            if (a == b && b == c) {
                cout << "Equilateral triangle" << endl;
            }
        } 
    }
    return 0;
}