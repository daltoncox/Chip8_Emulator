#ifndef WindowHeader
#define WindowHeader

#include <SDL3/SDL.h>

using namespace std;
class Window {
   public:
    Window(const char* title, int width, int height, int scale, int pitch);
    ~Window();

    void UpdateScreen(void const* buffer, int pitch);
    void ProcessInput(bool Keys[]);

   private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};

#endif
