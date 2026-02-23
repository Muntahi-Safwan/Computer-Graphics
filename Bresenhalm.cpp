#include<iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = (2 * dy) - dx;

    int x = x1;
    int y = y1;

    cout << x << "," << y << "," << p << endl;

    while (x < x2) {
        if (p < 0) {
            x = x + 1;
            p = p + 2 * dy;
        } else {
            p = p + 2 * (dy - dx);
            x = x + 1;
            y = y + 1;
        }
        cout << x << "," << y << "," << p << endl;
    }

    return 0;
}
