#pragma once

class Note {
public:
    static constexpr float C = 261.63f;
    static constexpr float D = 293.66f;
    static constexpr float E = 329.63f;
    static constexpr float F = 349.23f;
    static constexpr float G = 392.00f;
    static constexpr float A = 440.00f;
    static constexpr float B = 493.88f;
    
    // Sharps.
    static constexpr float CS = 277.18f;
    static constexpr float DS = 311.13f;
    static constexpr float FS = 369.99f;
    static constexpr float GS = 415.30f;
    static constexpr float AS = 466.16f;

    static inline float get_note(char c) {
        switch (c) {
        case 'a':
            return Note::C;
        case 's':
            return Note::D;
        case 'd':
            return Note::E;
        case 'f':
            return Note::F;
        case 'g':
            return Note::G;
        case 'h':
            return Note::A;
        case 'j':
            return Note::B;
        case 'w':
            return Note::CS;
        case 'e':
            return Note::DS;
        case 'r':
            return Note::FS;
        case 't':
            return Note::GS;
        case 'y':
            return Note::AS;
        default:
            return 0.0f;
        }
    }
};
