#include <SDL2/SDL.h>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"

int main(int argc, char* argv[])
{
    Point<double> se(100, 200);
    Point<double> sa(300, 400);
    Point<double> sz(200, 200);
    Rectangle Sq(se, sa);
    Circle Ci(sz, 50);
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                Sq.draw(renderer);
                Ci.draw(renderer);
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}
