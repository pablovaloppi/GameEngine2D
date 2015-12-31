#include "Input.h"

Input::Input()
{

}

Input::~Input()
{
}

bool Input::processEvent()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			return false;
			break;
		case SDL_MOUSEMOTION:
		//std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}
	}
	return true;
}
 
bool Input::getKeyDown(Key key)
{
	return _keys[key];
}

bool Input::getKeyUp(Key key)
{
	return _keys[key];
}
