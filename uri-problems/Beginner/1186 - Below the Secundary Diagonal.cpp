#include <iostream>

using namespace std;

int main(){

    float m[12][12];
    float sum = 0;
    int count = 0;
    int max = 12;
    char o;

    cin >> o;

    for (int i = 0; i < 12; i++) {
        max--;
        for (int j = 0; j < 12; j++) {
            cin >> m[i][j];

            if (j > max) {
                sum += m[i][j];
                count++;
            }
        }
    }

    if (o == 'M') {
        printf("%.1lf\n", (sum/count));
    } else {
        printf("%.1lf\n", sum);
    }

    return 0;
}
