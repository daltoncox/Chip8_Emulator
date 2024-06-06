#ifndef WindowHeader
#define WindowHeader

using namespace std;
class Window {
   public:
    Window(int width, int height, int scale, int pitch);
    void UpdateScreen(void const* buffer, int pitch);
    void ProcessInput(bool Keys[]);
};

#endif
