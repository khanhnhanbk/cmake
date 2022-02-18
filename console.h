#ifdef WIN32
#include <windows.h>
// for nanosleep
#else
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#endif
void getSize(int &width, int &height)
{
#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;
    height = w.ws_row;
#endif
}
// unable to resize window
void resizeWindow(int width, int height)
{
#ifdef WIN32
    // resize window
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, width, height, TRUE);
#else
    // resize window
    struct winsize w;
    w.ws_col = width;
    w.ws_row = height;
    ioctl(STDOUT_FILENO, TIOCSWINSZ, &w);
#endif
}
// sleep for a number of milliseconds
void mySleep(int milliseconds)
{
#ifdef WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
// clear screen
void clearScreen()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}
// prevent window from resizing
void preventResize()
{
#ifdef WIN32
    HWND console = GetConsoleWindow();
    LONG style = GetWindowLong(console, GWL_STYLE);
    style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
    SetWindowLong(console, GWL_STYLE, style);
#else
    // prevent window from resizing
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}