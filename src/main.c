
/**
*  main.c
*/
#include <SDL2/SDL.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "Header.h"
#include "Graphics.h"
#include "Delta.h"
#include "Player_Input.h"

#define ROWS 9
#define COLS 6

#define GAME_TITLE "Gengine"

int FULLSCREEN_ON   = 0;
int FRAMES_RENDERED = 0;
int SECONDS_ELAPSED = 0;
int EXIT            = 0;
int KEY_STATE_LEN;

int integer_in_range_of(int down, int up)
{
    return (rand() % (up - down)) + down;
}
int array[ROWS][COLS] = {
    //"a" char array
    { 0, 0, 0, 0, 0, 0 },  //- - - - - -
    { 0, 1, 1, 1, 1, 0 },  //- * * * * -
    { 1, 0, 0, 0, 0, 1 },  //* - - - - *
    { 0, 0, 0, 0, 0, 1 },  //- - - - - *
    { 0, 1, 1, 1, 1, 1 },  //- * * * * *
    { 1, 0, 0, 0, 0, 1 },  //* - - - - *
    { 1, 0, 0, 0, 1, 1 },  //* - - - * *
    { 0, 1, 1, 1, 0, 1 },  //- * * * - *
    { 0, 0, 0, 0, 0, 0 },  //- - - - - -
};
double ret_d_shit_color(double freq, int num, int i)
{
    return sin(freq * i + num) * 127 + 128;
}
int main(int argc, char** argv)
{
    Uint8* KEY_STATE = (Uint8*)SDL_GetKeyboardState(&KEY_STATE_LEN);
    Window window;
    Renderer renderer;

    Thread input_thread;

    double freq = 0.3;

    SDL_init();
    set_up_timer();

    window       = make_window(GAME_TITLE);
    renderer     = make_renderer(&window);
    input_thread = SDL_CreateThread(input_handler, "input_handler", NULL);

    SDL_DetachThread(input_thread);
    srand(time(0));
    while (!EXIT) {
        start_timer();

        SDL_RenderClear(renderer);

        for (size_t i = 0; i < 32; i++) {

            SDL_SetRenderDrawColor(renderer, ret_d_shit_color(freq, 0, i), ret_d_shit_color(freq, 2, i), ret_d_shit_color(freq, 4, i), 0);
            for (size_t k = 0; k < WINDOW_WIDTH; k++) {
                /* code */
                SDL_RenderDrawPoint(renderer, i, k);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        SDL_RenderPresent(renderer);

        delay();
        reset_timer();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
