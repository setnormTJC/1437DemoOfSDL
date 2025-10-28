#include "SDLWrapper.h"

#include<chrono> 
#include<thread> //used for a SLEEP function (for framerate)

#include "Color.h"


//#include "Texture.h"


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

    //std::vector<int> lineXValues =
    //{
    //    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    //};


    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            if (frameCount % 2 == 0)
            {
                SDL_SetRenderDrawColor(pRenderer, theUgliestColor.r, theUgliestColor.g, theUgliestColor.b,
                    theUgliestColor.a);
            }

            else
            {
                Color pink_thePrettiestColor = { 255, 192, 203, 255 };
                SDL_SetRenderDrawColor
                (   pRenderer, 
                    pink_thePrettiestColor.r, 
                    pink_thePrettiestColor.g, 
                    pink_thePrettiestColor.b,
                    pink_thePrettiestColor.a);
            }
            SDL_RenderPoint(pRenderer, x, y);
        }
    }

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

        float cameraStepSize = 0.1f;
        bool isPaused = false;
        float thetaRotation = M_PI / 10.0f; //let this be the same for x, y, and z
        float objectStepSize = 0.1f;

        /*Might consider moving this to a helper method (ex: handleKeyboardEvent)*/
        //switch (keyID) //note that cases are organized alphabetically (not "logically") 
        //{
        //case SDLK_A: //note that the user is allowed to enter 'a' here 
        //    std::cout << "Moving left " << cameraStepSize << "\n";
        //    camera.moveLeft(cameraStepSize);
        //    break;

        //case SDLK_D: //the K stands for "key" probably
        //    std::cout << "Moving right " << cameraStepSize << "\n";
        //    camera.moveRight(cameraStepSize);
        //    break;

        //case SDLK_DOWN:
        //    std::cout << "Moving down " << cameraStepSize << "\n";
        //    camera.moveDown(cameraStepSize);
        //    break;

        //case SDLK_P:
        //    std::cout << "Pausing animation...\n";
        //    std::system("pause");
        //    break;

        //case SDLK_S:
        //    std::cout << "Moving backerds\n";
        //    camera.moveBackward(cameraStepSize);
        //    break;

        //case SDLK_T: //added this case just to test getting object off of the screen - I should improve this later
        //    //or just give a Mesh its own "natural" movement/animation that is not controlled by the user
        //    std::cout << "Translating object to the right\n";
        //    auto newTranslation = meshInstance.getTranslation();
        //    newTranslation.x -= objectStepSize;
        //    meshInstance.setTranslation(newTranslation);
        //    break;

        //case SDLK_UP:
        //    std::cout << "Moving up " << cameraStepSize << "\n";
        //    camera.moveUp(cameraStepSize);
        //    break;

        //case SDLK_W:
        //    std::cout << "Moving camera forward\n";
        //    camera.moveForward(cameraStepSize);
        //    break;

        //case SDLK_X:
        //    std::cout << "Rotating about x by " << ((180.0f) / M_PI) * thetaRotation << "\n";
        //    auto newXRotation = meshInstance.getRotation(); //get the current rotation vector 
        //    newXRotation.x += thetaRotation; //and update the x-component
        //    meshInstance.setRotation(newXRotation);
        //    break;

        //case SDLK_Y:
        //    std::cout << "Rotating about y by " << ((180.0f) / M_PI) * thetaRotation << "\n";
        //    auto newYRotation = meshInstance.getRotation();
        //    newYRotation.y += thetaRotation;
        //    meshInstance.setRotation(newYRotation);
        //    break;

        //case SDLK_Z:
        //    std::cout << "Rotating about zed by " << ((180.0f) / M_PI) * thetaRotation << "\n";
        //    auto newZRotation = meshInstance.getRotation();
        //    newZRotation.z += thetaRotation;
        //    meshInstance.setRotation(newZRotation);
        //    break;

        //default:
        //    std::cout << "Unhandled key pressed\n";
        //    break;
        //}

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




