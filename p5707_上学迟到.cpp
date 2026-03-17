#include<bits/stdc++.h>
using namespace std;
int main() {
    int s, v;
    cin >> s >> v;
    int walk_time = (s + v - 1) / v;
    int total_cost = walk_time + 10;
    int target_time = 8 * 60;
    int start_time = target_time - total_cost;
    if (start_time < 0) {
        start_time += 24 * 60;
    }
    int h = start_time / 60;
    int m = start_time % 60;
    cout << setw(2) << setfill('0');
    cout << h;
    cout << ":" ;
    cout << setw(2) << setfill('0');
    cout << m << endl;
    return 0;
}