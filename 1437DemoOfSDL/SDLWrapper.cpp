#include "SDLWrapper.h"

#include<chrono> 
#include<thread> //used for a SLEEP function (for framerate)

#include "Color.h"
#include"Sound.h"

SDLWrapper::SDLWrapper(int width, int height)
    :width(width), height(height)
{

}

SDL_AppResult SDLWrapper::init()
{
    if (SDL_CreateWindowAndRenderer("A terrific window title", width, height,
        0, &pWindow, &pRenderer) != 0)
    {
        SDL_Log("Failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    //SDL_AudioSpec desired{};
    //desired.freq = 48000;
    //desired.format = SDL_AUDIO_F32;
    //desired.channels = 1;
    ////SDL_Audio_Device
    //audioDevice = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &desired, &audioSpec, 0);

    //if (audioDevice == 0) {
    //    SDL_Log("Failed to open audio device: %s", SDL_GetError());
    //    return SDL_APP_FAILURE;
    //}

    //SDL_PauseAudioDevice(audioDevice, 0); // start playback


    return SDL_APP_CONTINUE;
}

SDLWrapper::~SDLWrapper()
{
    quit(SDL_APP_SUCCESS);

}

int SDLWrapper::run()
{

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }

    if (!init()) {
        SDL_Quit();
        return -1;
    }

    bool quitFlag = false;
    SDL_Event event;

    while (!quitFlag)
    {
        // Poll events
        while (SDL_PollEvent(&event))
        {
            if (handleEvent(&event) == SDL_APP_SUCCESS)
                quitFlag = true;
        }

        if (iterate() == SDL_APP_FAILURE)
            quitFlag = true;
    }

    quit(SDL_APP_SUCCESS);
    SDL_Quit();
    return 0;
}



SDL_AppResult SDLWrapper::iterate()
{

    auto frameStart = std::chrono::high_resolution_clock::now();


    draw();

    advanceFrame(frameStart);

    return SDL_APP_CONTINUE; //what is a fail condition in this function? 
}

void SDLWrapper::draw(/*const std::unordered_map<Vec2, Color>& rasteredPixels*/) const
{

    Color theUgliestColor = {255 , 255, 0, 255 }; //yellow, according to ONE student

   
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    float xStart = 100; 
    float xEnd = 400; 

    float yStart = 200; 
    float yEnd = 500; 

    float m = (yEnd - yStart) / (xEnd - xStart); 

   
    for (int x = xStart; x < xEnd; ++x) //caution: float to int conversion 
    {
        if (frameCount % 2 == 0)
        {
            SDL_SetRenderDrawColor(pRenderer, theUgliestColor.r, theUgliestColor.g, theUgliestColor.b,
                theUgliestColor.a);
        }

        else
        {
            SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255); 
        }

        int y = 123; 

        SDL_RenderPoint(pRenderer, x, y);
    
    }

    //SDL_audio_device

    SDL_RenderPresent(pRenderer);
    std::cout << "Draw it, draw it real good- frame count: " << frameCount << "\n";

}

void SDLWrapper::advanceFrame(const std::chrono::steady_clock::time_point& frameStart)
{
    auto frameEnd = std::chrono::high_resolution_clock::now();
    long long frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart).count();
    /*Unlikely to need a long long, but .count() returns long long*/
    if (frameTime < frameDelay.count())
        std::this_thread::sleep_for(frameDelay - std::chrono::milliseconds(frameTime));

    frameCount++;
}


SDL_AppResult SDLWrapper::handleEvent(SDL_Event* pEvent/*, Camera& camera, MeshInstance& meshInstance*/)
{
    if (pEvent->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }

    else if (pEvent->type == SDL_EVENT_KEY_DOWN)
    {
        Uint32 keyID = pEvent->key.key;

        std::cout << keyID << "\n";


    }


    return SDL_APP_CONTINUE;
}

void SDLWrapper::quit(SDL_AppResult)
{
    if (pRenderer)
    {
        SDL_DestroyRenderer(pRenderer);
    }

    if (pWindow)
    {
        SDL_DestroyWindow(pWindow);
    }
}




