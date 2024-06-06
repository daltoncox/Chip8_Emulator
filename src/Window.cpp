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
bool Window::ProcessInput(bool key[]) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                return false;
            case SDL_EVENT_KEY_DOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        return false;
                    case SDLK_1:
                        key[0x1] = true;
                        break;
                    case SDLK_2:
                        key[0x2] = true;
                        break;
                    case SDLK_3:
                        key[0x3] = true;
                        break;
                    case SDLK_q:
                        key[0x4] = true;
                    case SDLK_w:
                        key[0x5] = true;
                        break;
                    case SDLK_e:
                        key[0x6] = true;
                        break;
                    case SDLK_a:
                        key[0x7] = true;
                        break;
                    case SDLK_s:
                        key[0x8] = true;
                        break;
                    case SDLK_d:
                        key[0x9] = true;
                        break;
                    case SDLK_x:
                        key[0x0] = true;
                        break;
                    case SDLK_z:
                        key[0xA] = true;
                        break;
                    case SDLK_c:
                        key[0xB] = true;
                        break;
                    case SDLK_4:
                        key[0xC] = true;
                        break;
                    case SDLK_r:
                        key[0xD] = true;
                        break;
                    case SDLK_f:
                        key[0xE] = true;
                        break;
                    case SDLK_v:
                        key[0xF] = true;
                        break;
                }
            case SDL_EVENT_KEY_UP:
                switch (event.key.keysym.sym) {
                    case SDLK_1:
                        key[0x1] = false;
                        break;
                    case SDLK_2:
                        key[0x2] = false;
                        break;
                    case SDLK_3:
                        key[0x3] = false;
                        break;
                    case SDLK_q:
                        key[0x4] = false;
                    case SDLK_w:
                        key[0x5] = false;
                        break;
                    case SDLK_e:
                        key[0x6] = false;
                        break;
                    case SDLK_a:
                        key[0x7] = false;
                        break;
                    case SDLK_s:
                        key[0x8] = false;
                        break;
                    case SDLK_d:
                        key[0x9] = false;
                        break;
                    case SDLK_x:
                        key[0x0] = false;
                        break;
                    case SDLK_z:
                        key[0xA] = false;
                        break;
                    case SDLK_c:
                        key[0xB] = false;
                        break;
                    case SDLK_4:
                        key[0xC] = false;
                        break;
                    case SDLK_r:
                        key[0xD] = false;
                        break;
                    case SDLK_f:
                        key[0xE] = false;
                        break;
                    case SDLK_v:
                        key[0xF] = false;
                        break;
                }
        }
    }
}