#include "game.hpp"

#include "raylib.h"
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include <iostream>


Game::Game() {
    // Initialize window and set some flags.
    InitWindow(
        720,
        720,
        "WINDOW_TITLE"
    );

#if defined(PLATFORM_WEB)
#else
    SetWindowState(FLAG_VSYNC_HINT);
#endif

    std::cout << "[Game]: created.\n";
}


Game::~Game() {
    CloseWindow();

    std::cout << "[Game]: destroyed.\n";
}


void Game::run() {
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(m_updateDrawFrame, 0, 1);
#else
    while(!WindowShouldClose()) {
        m_updateDrawFrame();
    }
#endif
}


void Game::m_updateDrawFrame() {
    // Update and draw the game.
    m_tick();
    m_draw();
}


void Game::m_tick() {
}


void Game::m_draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    Texture2D testTexture{ LoadTexture("resources/test_texture.png") };
    DrawTexture(testTexture, 100, 100, WHITE);

    EndDrawing();
}
