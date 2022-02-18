#include <bits/stdc++.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <sys/types.h>
#include <sys/wait.h>
// #include <Windows.h>

using namespace std;
const string CHARACTER = "0123456789!@#$%^&*";
const int CHARACTER_SIZE = CHARACTER.size();
const int MAX_LENGTH = 80;
const int MAX_SIZE = 20;
string generateLine(int length) {
    // random 
    string line;
    for (int i = 0; i < length; i++) {
        int num = rand() % 255;
        if (num < CHARACTER_SIZE) {
            line += CHARACTER[num];
        } else {
            line += ' ';
        }
    }
    return line;
}
void printLines(vector<string> lines) {
    system("clear");
    // print reverse order
    for (int i = lines.size() - 1; i >= 0; i--) {
        cout << lines[i] << endl;
    }
}
void nextLine(vector<string> &lines) {
    string line = generateLine(MAX_LENGTH);
    lines.push_back(line);
    // remove last line if it is too long
    if (lines.size() > MAX_SIZE) {
        // lines.pop_back();
        // delete first line
        lines.erase(lines.begin());
    }
}
int main()
{
  srand(time(NULL));
    system("clear");
    vector<string> lines;
    while (true) {
        nextLine(lines);
        printLines(lines);
        // sleep for 0.5 seconds
        usleep(70000); 
    }
    return 0;
}