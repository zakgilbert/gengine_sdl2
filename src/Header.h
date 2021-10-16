#ifndef HEADER_H
#define HEADER_H

#define PRINT 1
#define FPS 60
#define WINDOW_WIDTH 255 * 2
#define WINDOW_HEIGHT 255 * 2
#define PRIME_1 163              /* Prime numbers for seeding has tables */
#define PRIME_2 151      

typedef SDL_Renderer* Renderer;
typedef SDL_Window* Window;
typedef SDL_Thread* Thread;

extern int FULLSCREEN_ON;
extern int FRAMES_RENDERED;
extern int SECONDS_ELAPSED;
extern int EXIT;
extern Uint8* KEY_STATE;

#endif /* HEADER_H */
