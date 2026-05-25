#include <algorithm>
#include <iostream>
using namespace std;

// - - - - - - - - - -
bool UniqueWaterGen = false;

// - - - - - - - - - -
void ResetMap();
void ScatterRocks();
void DrawWater(int density);
void PrintMap();


char Map[20][20];
// - - - - - - - - - -

int main()
{
    srand(time(0)); // makes randomness actually random

    int waterDensity = 1;

    ResetMap();
    ScatterRocks();
    DrawWater(waterDensity);
    PrintMap();
}

// - - - - - - - - - -

void ResetMap()
{
    for (int col = 0; col < 20; col++) {
        for (int row = 0; row < 20; row++) {

            Map[row][col] = ' ';
        }
    }
}

void ScatterRocks()
{
    for (int rock = 0; rock < 80; rock++) {

        int randRow = rand() % 21;
        int randCol = rand() % 21;


        Map[randRow][randCol] = 'o';

    }
}

void DrawWater(int density) // lowkey have no idea why this makes the water the way it does, but it's cool
{
    int origin = rand() % 21;

    if (origin > 20 - density) {
        origin = density;
    }


    int width = density;
    int offset = 0;

    for (int water = 0; water < density; water++) {

        for (int col = 0; col < 20; col++) {

            for (int row = 0; row < density; row++) {

                int effectWidth = rand() % 4;
                int offsetWidth = rand() % 4;



                if (effectWidth == 1) {
                    width = width > 1 ? width - 1 : 1;
                }
                else if (effectWidth == 2) {
                    width = width < 19 ? width + 1 : 19;
                }

                if (offsetWidth == 1) {
                    offset = offset > 1 ? offset - 1 : 1;
                }
                else if (offsetWidth == 2) {
                    offset = offset < 19 ? offset + 1 : 19;
                }

                //cout << "\n" << origin + row + width;

                if (!UniqueWaterGen) {
                    for (int i = 0; i < width; i++) {
                        Map[origin + row + i + offset][col] = '~';

                    }
                }
                else {
                    Map[origin + row + width + offset][col] = '~';
                }
            }
        }
    }
}

void PrintMap()
{
    for (int col = 0; col < 20; col++) {

        cout << "\n";

        for (int row = 0; row < 20; row++) {
            cout << Map[row][col] << "  ";
        }
    }
}