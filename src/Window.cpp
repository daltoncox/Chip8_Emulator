#include "Window.h"

Window::Window(const char* title, int width, int height, int scale) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, width * scale, height * scale,
                              SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, NULL);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                SDL_TEXTUREACCESS_STREAMING, width, height);

    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
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
bool Window::ProcessInput(bool* Keys) {
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
                        Keys[1] = 1;

                        break;
                    case SDLK_2:
                        Keys[0x2] = 1;
                        break;
                    case SDLK_3:
                        Keys[0x3] = 1;
                        break;
                    case SDLK_q:
                        Keys[0x4] = 1;
                        break;
                    case SDLK_w:
                        Keys[0x5] = 1;
                        break;
                    case SDLK_e:
                        Keys[0x6] = 1;
                        break;
                    case SDLK_a:
                        Keys[0x7] = 1;
                        break;
                    case SDLK_s:
                        Keys[0x8] = 1;
                        break;
                    case SDLK_d:
                        Keys[0x9] = 1;
                        break;
                    case SDLK_x:
                        Keys[0x0] = 1;
                        break;
                    case SDLK_z:
                        Keys[0xA] = 1;
                        break;
                    case SDLK_c:
                        Keys[0xB] = 1;
                        break;
                    case SDLK_4:
                        Keys[0xC] = 1;
                        break;
                    case SDLK_r:
                        Keys[0xD] = 1;
                        break;
                    case SDLK_f:
                        Keys[0xE] = 1;
                        break;
                    case SDLK_v:
                        Keys[0xF] = 1;
                        break;
                }
                break;
            case SDL_EVENT_KEY_UP:
                switch (event.key.keysym.sym) {
                    case SDLK_1:
                        Keys[1] = 0;
                        break;
                    case SDLK_2:
                        Keys[0x2] = 0;
                        break;
                    case SDLK_3:
                        Keys[0x3] = 0;
                        break;
                    case SDLK_q:
                        Keys[0x4] = 0;
                        break;
                    case SDLK_w:
                        Keys[0x5] = 0;
                        break;
                    case SDLK_e:
                        Keys[0x6] = 0;
                        break;
                    case SDLK_a:
                        Keys[0x7] = 0;
                        break;
                    case SDLK_s:
                        Keys[0x8] = 0;
                        break;
                    case SDLK_d:
                        Keys[0x9] = 0;
                        break;
                    case SDLK_x:
                        Keys[0x0] = 0;
                        break;
                    case SDLK_z:
                        Keys[0xA] = 0;
                        break;
                    case SDLK_c:
                        Keys[0xB] = 0;
                        break;
                    case SDLK_4:
                        Keys[0xC] = 0;
                        break;
                    case SDLK_r:
                        Keys[0xD] = 0;
                        break;
                    case SDLK_f:
                        Keys[0xE] = 0;
                        break;
                    case SDLK_v:
                        Keys[0xF] = 0;
                        break;
                }
                break;
        }
    }
    return true;
}