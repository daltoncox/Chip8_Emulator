#include "Window.h"

Window::Window(const char* title, int width, int height, int scale, int pitch) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, width * scale, height * scale,
                              SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, NULL);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                SDL_TEXTUREACCESS_STREAMING, width, height);
}
Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

void Window::UpdateScreen(void const* buffer, int pitch) {
    SDL_UpdateTexture(texture, NULL, buffer, pitch);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
short Window::ProcessInput() {}