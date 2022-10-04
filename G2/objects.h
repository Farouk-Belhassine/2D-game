#include <SDL/SDL_image.h>

typedef struct{
	SDL_Rect healthpos;
}OBJECTS;

void initobjects(OBJECTS *object);
void drawobject(int cam, SDL_Rect *objectpos, int m);
