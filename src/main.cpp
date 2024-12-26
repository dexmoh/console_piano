#include <iostream>
#include <windows.h>
#include <conio.h>

#include "note.hpp"

inline void draw_keyboard(int tone_duration, int scale);

int main(void) {
    bool is_running = true;
    int tone_duration = 600;
    int scale = 0;

    while (is_running) {
        draw_keyboard(tone_duration, scale);

        // Get user input.
        char c = _getch();
        float note = Note::get_note(c);

        // If the user didn't play a note, check for other inputs.
        if (note == 0.0f) {
            switch (c) {
            // Exit the program.
            case 27: // Escape key.
                is_running = false;
                continue;
            // Change tone duration.
            case '1':
                tone_duration = 400;
                continue;
            case '2':
                tone_duration = 600;
                continue;
            case '3':
                tone_duration = 900;
                continue;
            // Scale down.
            case '4':
                if (scale > -1)
                    scale--;
                continue;
            // Scale up.
            case '5':
                if (scale < 1)
                    scale++;
                continue;
            default:
                continue;
            }
        }

        switch (scale) {
        case -1:
            note /= 2;
            break;
        case 1:
            note *= 2;
            break;
        default:
            break;
        }

        std::cout << c;
        Beep(note, tone_duration);
    }

    return 0;
}

inline void draw_keyboard(int tone_duration, int scale) {
    // Clear the screen.
    system("CLS");

    // Print keyboard.
    std::cout <<
        "+--------------------------------------------------+\n"
        "| `   1  2  3  4  5  6  7  8  9  0  -  =   <--     |\n"
        "| Tab       q  W  E  R  T  Y  u  i  o  p  [  ] \\   |\n"
        "| Caps Lock  A  S  D  F  G  H  J  k  l  ;  ' Enter |\n"
        "| Shift       z  x  c  v  b  n  m  ,  .  /  Shift  |\n"
        "| Ctrl   Fn   Alt      Space     Alt   Ctrl        |\n"
        "+--------------------------------------------------+\n"
        "\nUse keys A, S, D, F, G, H, J, W, E, R, T, Y to play the notes.\n"
        "Press 1-3 to change the tone duration.\n"
        "Press 4-5 to increase/decrease the pitch.\n"
        "Press ESC to exit the program.\n"
        "\nTone duration: " << tone_duration << "ms\n"
        "Scale: " << scale << "\n"
        "\nNote: ";
}
