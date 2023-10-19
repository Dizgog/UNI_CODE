//Normantas Kuolas
//Using SDL
//Version 1.3
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "scoreboard.h"
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int vx = 20;
const int vy = 10;
int Double_jump=0;
int speed = 1, score = 0;
//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//Loads media
bool loadMedia();

//Load dino
bool loadDino();

//Handles movement
void handleEvent(e );

//Reloads the screen
void Reload();

//WIP
void Start();

//Loads data
void load_data();

//Saves data
void save_data();

//Checks for collision
bool collision ();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The renderer
SDL_Renderer* gRenderer = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

//Loads the dino
SDL_Surface* gJPGDino = NULL;

//Loads the waves (rad)
SDL_Surface* gPNGWave = NULL;

//Creates a pointer for file
FILE *fptr;

//Sets up dino and wavev dimension
SDL_Rect Dino ={
    .x = 200,
	.y = 300,
	.w = 40,
	.h = 40
};

SDL_Rect Wave ={
    .x = 40,
    .y = 300,
    .w = 40,
    .h = 40
};

SDL_Rect Score ={
      .x = 0,
      .y = 0,
      .w = 50,
      .h = 50
};
int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
    }
	//The main game loop
    GameLoop();

	return 0;
}

void GameLoop()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Loads data
    load_data();
            while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
					    save_data();
						quit = true;
					}
				}
            handleEvent( e );
            Reload();
			objects();
			SDL_Delay(1000/60);
			    if (!collision())
                {
                  scoreboard(score);
                  base_state();
                  quit = true;
			    }
			}
    //Free resources and close SDL
	close();
}

bool init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "Dino game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
		    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			//Initialize PNG loading

			//Initialize renderer color
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface( gPNGSurface );
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

    //Destroy dino
	SDL_FreeSurface( gJPGDino );
    gJPGDino = NULL;

    SDL_FreeSurface( gPNGWave );
	gPNGWave = NULL;

	//Quit SDL subsystems
	IMG_Quit();

	SDL_Quit();

	fclose(fptr);
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = IMG_Load( "art/Background.png" );
	if( gPNGSurface == NULL )
	{
		printf( "Failed to load background image!\n" );
		success = false;
	}

	gJPGDino = IMG_Load("art/Dino.jpg");
	if( gJPGDino == NULL )
	{
		printf( "Failed to load dino image!\n" );
		success = false;
	}

	gPNGWave = IMG_Load("art/Wave.png");
	if( gPNGWave == NULL )
	{
		printf( "Failed to load dino image!\n" );
		success = false;
	}


	SDL_SetColorKey( gJPGDino, SDL_TRUE, SDL_MapRGB( gJPGDino->format, 0, 0, 0 ) );
	return success;
}


void handleEvent( e)
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
                //Checks if the player jumped twice
                if(Dino.y==300)
                Double_jump=0;
                //The jumping mechanic
				if ( currentKeyStates[ SDL_SCANCODE_SPACE ] && Dino.y > 240 && Double_jump<=2)
                {
				Dino.y -=40;
				Dino.x +=5;
				Double_jump++;
                }
}

void Reload()
{
                //Apply the PNG image
				SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );

				//Apply dino image
				SDL_BlitScaled( gJPGDino, NULL, gScreenSurface, &Dino );

                //Apply the wawes
				SDL_BlitScaled( gPNGWave, NULL, gScreenSurface, &Wave );

				//Gravity
				if (Dino.y<300)
                {
				for (int i=0; 1>=i; i++)
                {
                    Dino.y += i;
                }
                }
                else if (Dino.x>200)

                for (int i=0; 1>=i; i++)
                {
                    Dino.x -= i;
                }

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
}

void objects()
{
    //Makes the wave go
   if(Wave.x<=0)
   {
    score++;
    Wave.x = 600;
    speed=rand() % (11 + 1 - 1) + 1;
   }
       Wave.x -= speed;
}

bool collision()
{
    bool success = true;
    if(Dino.x<Wave.x+20 &Dino.x>Wave.x&Dino.y>Wave.y-39)
    {
    printf("You got washed away by the wave\n");
    success = false;
    }
    return success;
}


void load_data()
{
fptr = fopen("save","rb");

fscanf(fptr,"%d %d %d %d\n", &Dino.x, &Dino.y, &Dino.w, &Dino.h);
fscanf(fptr,"%d %d %d %d\n", &Wave.x, &Wave.y, &Wave.w, &Wave.h);
fscanf(fptr, "%d %d", &speed, &score);
}

void save_data()
{
fptr = fopen("save","wb");

fprintf(fptr, "%d %d %d %d\n", Dino.x, Dino.y, Dino.w, Dino.h);
fprintf(fptr,"%d %d %d %d\n", Wave.x, Wave.y, Wave.w, Wave.h);
fprintf(fptr, "%d %d", speed, score);
}

void base_state()
{
fptr = fopen("save","wb");

fprintf(fptr, "%d %d %d %d\n", 200, 300, 40, 40);
fprintf(fptr, "%d %d %d %d\n", 40, 300, 40, 40);
fprintf(fptr, "%d %d",1,0);
}

