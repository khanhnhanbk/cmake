#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "console.h"
using namespace std;
const string CHARACTER = "0123456789!@#$%^&*";
const int CHARACTER_SIZE = CHARACTER.size();
int WIDTH;
int HEIGHT;
string generateLine(int length)
{
    // random
    string line;
    for (int i = 0; i < length; i++)
    {
        int num = rand() % 255;
        if (num < CHARACTER_SIZE)
        {
            line += CHARACTER[num];
        }
        else
        {
            line += ' ';
        }
    }
    return line;
}
void printLines(vector<string> lines)
{
    clearScreen();
    // change text color
    setTextColor(rand() % 10);
    // print reverse order
    for (int i = lines.size() - 1; i >= 0; i--)
    {
        cout << lines[i] << endl;
    }
}
void nextLine(vector<string> &lines)
{
    string line = generateLine(WIDTH);
    lines.push_back(line);
    // remove last line if it is too long
    if (lines.size() > HEIGHT)
    {
        // lines.pop_back();
        // delete first line
        lines.erase(lines.begin());
    }
}
int main()
{
    srand(time(NULL));
    getSize(WIDTH, HEIGHT);
    HEIGHT--;
    vector<string> lines;
    while (true)
    {
        nextLine(lines);
        printLines(lines);
        // sleep for 0.5 seconds
        usleep(70000);
    }
    return 0;
}