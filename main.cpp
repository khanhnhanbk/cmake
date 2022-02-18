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
bool FALLDOWN = false;
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
    for (int i = 0; i < lines.size(); i++)
    {
        setTextColor(rand()%10);
        cout << lines[i] << endl;
    }
}
void nextLine(vector<string> &lines)
{
    string line = generateLine(WIDTH);
    // lines.push_back(line);
    // // remove last line if it is too long
    // if (lines.size() > HEIGHT)
    // {
    //     // lines.pop_back();
    //     // delete first line
    //     lines.erase(lines.begin());
    // }
    if (FALLDOWN)
    {
        lines.push_back(line);
        // remove last line if it is too long
        if (lines.size() > HEIGHT)
        {
            // lines.pop_back();
            // delete first line
            lines.erase(lines.begin());
        }
    }
    else
    {
        lines.insert(lines.begin(), line);
        // remove last line if it is too long
        if (lines.size() > HEIGHT)
        {
            // lines.pop_back();
            // delete first line
            lines.erase(lines.begin() + HEIGHT);
        }
    }
}
int main()
{
    // srand(time(NULL));
    getSize(WIDTH, HEIGHT);
    HEIGHT--;
    vector<string> lines;
    int count = 0;
    while (true)
    {
        nextLine(lines);
        printLines(lines);
        // sleep for 0.5 seconds
        mySleep(30);
        count += (rand() % 19 + 1);
        if (count % 67 == 0)
        {
            FALLDOWN = !FALLDOWN;
            count = 0;
        }
    }
    return 0;
}