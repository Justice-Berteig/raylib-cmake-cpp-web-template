/*
Class to represent and handle the full game.
*/

#pragma once


class Game {
    public:
        Game();
        ~Game();

        /*
        Run method starts the game and controls the game loop.
        */
        void run();

    private:
        /*
        Function calls m_tick() and m_draw().
        Called by main loop.
        */
        void m_updateDrawFrame();

        /*
        Tick function for processing every game tick.
        */
        void m_tick();

        /*
        Draw function for drawing every frame.
        */
        void m_draw();
};
