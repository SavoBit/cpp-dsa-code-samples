#include <iostream>
#include <math.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20

using namespace std;

class Terminal {
public:
    Terminal() {
        for(int y = 0; y < SCREEN_HEIGHT; y++) {
            for(int x = 0; x < SCREEN_WIDTH; x++) {
                set(x, y, '.');
            }
        }
    }

    void print() {
        for(int y = 0; y < SCREEN_HEIGHT; y++) {
            for(int x = 0; x < SCREEN_WIDTH; x++) {
                cout << get(x, y);
            }
            cout << endl;
        }
    }

    char get(int x, int y) {
        return buffer[y][x];
    }

    void set(int x, int y, char c) {
        if(y >= SCREEN_HEIGHT || x >= SCREEN_WIDTH) {
            return;
        }

        buffer[y][x] = c;
    }


    void drawRectangle(int x1, int y1, int x2, int y2) {
        for(int x = x1; x <= x2; x++) {
            set(x, y1, 'x');
            set(x, y2, 'x');
        }

        for(int y = y1; y <= y2; y++) {
            set(x1, y, 'x');
            set(x2, y, 'x');
        }
    }

    void drawCircle(int x, int y, int radius) {
        for(double angle = 0; angle <= 360; angle += 5) {
            double radian = angle*180/3.1416;
            int x1 = x + radius * cos(radian);
            int y1 = y + radius * sin(radian);

            set(x1, y1, 'x');
        }
    }

private:
    int width;
    int height;
    char buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
};


int main(void) {
    Terminal screen = Terminal();

//    screen.set(15, 10, 'o');
//    screen.drawRectangle(10, 1, 30, 10);

//    screen.drawCircle(25, 10, 8);

    screen.drawRectangle(0, 0, 4, 4);
    screen.drawRectangle(3, 3, 8, 8);
    screen.drawRectangle(7, 7, 12, 12);
    screen.drawRectangle(11, 11, 16, 16);
    screen.drawRectangle(15, 15, 20, 20);
    screen.drawCircle(30, 10, 5);

    screen.print();

    return 0;
}
