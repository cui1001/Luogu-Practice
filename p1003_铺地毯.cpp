#include<bits/stdc++.h>
using namespace std;

//用结构体存每块地毯的信息，方便管理
struct Carpet {
    int a; //左下角x坐标
    int b; //左下角y坐标
    int g; //地毯x方向延伸长度
    int k; //地毯y方向延伸长度
};

int main() {
    int n; //地毯总数
    cin >> n;

    //用vector存所有地毯的信息
    vector<Carpet> carpets(n);
    for (int i = 0; i < n; i++) {
        //输入每块地毯的a,b,g,k
        cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
    }

    int x, y; //所求的地面的点的坐标
    cin >> x >> y;

    int ans = -1; //答案，默认没被任何地毯盖住
    //关键：从后往前查！因为后铺的盖前面的，找到第一个盖住的就是最后盖的
    for (int i = n - 1; i >= 0; i--) {
        //取出第i块地毯的信息
        int a = carpets[i].a;
        int b = carpets[i].b;
        int g = carpets[i].g;
        int k = carpets[i].k;

        //判断点(x,y)是否在这块地毯范围内
        //条件1：x >= 地毯左下角a 且 x <= 地毯右下角a (a + g)
        //条件2：y >= 地毯左下角b 且 y <= 地毯右上角b (b + k)
        if (x >= a && x <= a + g && y >= b && y <= b + k) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}