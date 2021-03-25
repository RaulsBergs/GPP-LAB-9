#include <iostream>
#include <glew.h>
#include <wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Matrix3.h>

//Move cube with WASD keys

using namespace std;
using namespace sf;
using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};