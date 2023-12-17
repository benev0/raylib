/*
    WELCOME raylib EXAMPLES CONTRIBUTOR!

    This is a basic template to anyone ready to contribute with some code example for the library,
    here there are some guidelines on how to create an example to be included in raylib

    1. File naming: <module>_<description> - Lower case filename, words separated by underscore,
       no more than 3-4 words in total to describe the example. <module> referes to the primary
       raylib module the example is more related with (code, shapes, textures, models, shaders, raudio).
       i.e: core_input_multitouch, shapes_lines_bezier, shaders_palette_switch

    2. Follow below template structure, example info should list the module, the short description
       and the author of the example, twitter or github info could be also provided for the author.
       Short description should also be used on the title of the window.

    3. Code should be organized by sections:[Initialization]- [Update] - [Draw] - [De-Initialization]
       Place your code between the dotted lines for every section, please don't mix update logic with drawing
       and remember to unload all loaded resources.

    4. Code should follow raylib conventions: https://github.com/raysan5/raylib/wiki/raylib-coding-conventions
       Try to be very organized, using line-breaks appropiately.

    5. Add comments to the specific parts of code the example is focus on.
       Don't abuse with comments, try to be clear and impersonal on the comments.

    6. Try to keep the example simple, under 300 code lines if possible. Try to avoid external dependencies.
       Try to avoid defining functions outside the main(). Example should be as self-contained as possible.

    7. About external resources, they should be placed in a [resources] folder and those resources
       should be open and free for use and distribution. Avoid propietary content.

    8. Try to keep the example simple but with a creative touch.
       Simple but beautiful examples are more appealing to users!

    9. In case of additional information is required, just come to raylib Discord channel: example-contributions

    10. Have fun!

    The following files should be updated when adding a new example, it's planned to create some
    script to automatize this process but not available yet.

     - raylib/examples/<category>/<category>_example_name.c
     - raylib/examples/<category>/<category>_example_name.png
     - raylib/examples/<category>/resources/*.*
     - raylib/examples/Makefile
     - raylib/examples/Makefile.Web
     - raylib/examples/README.md
     - raylib/projects/VS2022/examples/<category>_example_name.vcxproj
     - raylib/projects/VS2022/raylib.sln
     - raylib.com/common/examples.js
     - raylib.com/examples/<category>/<category>_example_name.html
     - raylib.com/examples/<category>/<category>_example_name.data
     - raylib.com/examples/<category>/<category>_example_name.wasm
     - raylib.com/examples/<category>/<category>_example_name.js
*/

/*******************************************************************************************
*
*   raylib [core] example - Backspace input
*
*   Example originally created with raylib 5.0, last time updated with raylib 5.0
*
*   Example contributed by benevo (@benev0) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2023 benevo (@benev0)
*
********************************************************************************************/

#include "raylib.h"

#define MAX_INPUT_CHARS 40


bool isKeyChar(int);

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - backspace input");

    char textField[MAX_INPUT_CHARS + 1] = "\0";
    int usedSize = 0;

    SetTargetFPS(1);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        int letter = GetCharPressed();
        int key = GetKeyPressed();

        if(key)
            printf("%d, %d\n", letter, key);

        while (key > 0 || letter > 0)
        {

            if (key == KEY_BACKSPACE && usedSize > 0)
            {
                textField[usedSize - 1] = 0;
                usedSize--;
                key = GetKeyPressed();
            }
            else if (!isKeyChar(key))
            {
                key = GetKeyPressed();
            }
            else if ((letter > 0) && (letter >= 32) && (letter <= 125) && (usedSize < MAX_INPUT_CHARS))
            {
                textField[usedSize] = (char) letter;
                textField[usedSize + 1] = 0;
                usedSize++;
                letter = GetCharPressed();
                key = GetKeyPressed();
            }
            else
            {
                letter = GetCharPressed();
                key = GetKeyPressed();
            }
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // TODO: Draw everything that requires to be drawn at this point:

            DrawText(textField, 40, 200, 20, BLACK);  // Example

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

bool isKeyChar(int key)
{
    switch (key)
    {
    case KEY_SPACE:
    case KEY_APOSTROPHE:
    case KEY_COMMA...KEY_NINE:
    case KEY_SEMICOLON:
    case KEY_EQUAL:
    case KEY_A...KEY_Z:
    case KEY_LEFT_BRACKET...KEY_RIGHT_BRACKET:
    case KEY_GRAVE:
        return true;
    default:
        return false;
    }
}
