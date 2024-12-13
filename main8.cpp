#include <iostream>
using namespace std;

void Fractal_Pattern(int n, int i) {
    if (n < 1) return;
    Fractal_Pattern(n / 2, i);
    for (int j = 0; j < i; j++) cout << "  ";
    for (int j = 0; j < n; j++) cout << "* ";
    cout << "\n";
    Fractal_Pattern(n / 2, i + n / 2);
}
bool Is_Power_Of_Two(int n) {
    return (n > 0 && (n & (n - 1)) == 0);
}
void Draw_Pattern() {
    int size;
    cout << "Enter size of the pattern [must be a power of 2]: ";
    cin >> size;
    cout << endl;

    if (!Is_Power_Of_Two(size)) {
        cout << "The number is not a power of 2\n";
        return;
    }
    Fractal_Pattern(size, 0);
}
int main() {
    Draw_Pattern();
    return 0;
}