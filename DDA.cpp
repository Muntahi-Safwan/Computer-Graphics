#include<iostream>
#include<cmath>

using namespace std;

int main() {
    float x1,y1,x2,y2;
    cout << "Starting Coordinates: ";
    cin >> x1 >> y1;
    cout << "Ending Coordinates: ";
    cin >> x2 >> y2;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;
    float step;
    if(abs(dx) < abs(dy)) {
        step = abs(dy);
    } else {
        step = abs(dx);
    }
    float x = x1;
    float y = y1;
    for(int i = 0; i <= step; i++) {
        cout << round(x) << "," << round(y) << endl;
        if(m < 1) {
            x = x + 1;
            y = y+m;
        } else if (m > 1) {
            x = x+1/m;
            y = y + 1;
        } else {
            x = x + 1;
            y = y + 1;
        }
    }
    return 0;
}
