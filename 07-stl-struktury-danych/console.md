## Code 1
```cpp
#include <iostream>
#include <windows.h>

void SetCursorPos(int x, int y) {
    COORD cursorPos;
    cursorPos.X = x;
    cursorPos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}

int main() {
    // Set the console title
    SetConsoleTitle("Custom Console Title");

    // Change console text color to light green
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);

    // Set the cursor position to (10, 5)
    SetCursorPos(10, 5);

    std::cout << "Hello, this is a colored message at position (10, 5)!" << std::endl;

    // Reset text color to default (white)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    // Display a message box
    MessageBox(NULL, "Hello from a MessageBox!", "MessageBox Title", MB_OK | MB_ICONINFORMATION);

    return 0;
}
```
