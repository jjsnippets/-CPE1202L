#ifndef FORMATTING_H
    #define FORMATTING_H

    #define BOLD_TEXT printf("\e[1m")
    
    #define TEXT_RESET printf("\e[m")
    #define COLOR_RED printf("\e[91m")
    #define COLOR_GREEN printf("\e[92m")
    #define COLOR_BLUE printf("\e[94m")


    #define MOVE_UP(x) printf("\e[%dA", x)
    #define MOVE_DOWN(x) printf("\e[%dB", x)
    #define MOVE_LEFT(x) printf("\e[%dD", x)

#endif