#pragma once
#define _USE_MATH_DEFINES

#pragma warning(push)
#pragma warning(disable: 4820) //padding warning
#include <SDL3/SDL.h>
#pragma warning(pop)

#include<iostream> 
#include<vector>

//#include "Camera.h"
//#include "Mesh.h"
//#include "MeshInstance.h"
//#include"Rasterizer.h"
#include <thread>


class SDLWrapper
{
private:
	static constexpr int TARGET_FPS = 1;
	static constexpr std::chrono::milliseconds frameDelay{ 3'000 / TARGET_FPS };
	//delay for 3 seconds between frames - allow sound wave to play

	SDL_Window* pWindow = nullptr;
	SDL_Renderer* pRenderer = nullptr;

	int width{}, height{};
	int frameCount{};

	/*Audio guys............................*/
	SDL_AudioDeviceID audioDevice = 0; //the type is an alias for uint32
	SDL_AudioSpec audioSpec{}; //a struct (channel count, frequency, and format) 


public:
	SDLWrapper(int width, int height);
	int run();

	/*Prevents memory leak if exception throws and bypasses SDL calling the quit*/
	~SDLWrapper();

private:
	SDL_AppResult init();

	/*The beast*/
	SDL_AppResult iterate();

	/*handleEvent can update camera (zooming and panning) and meshInstance (rotating, scaling, translating object)*/
	SDL_AppResult handleEvent(SDL_Event* pEvent /*Camera& camera, MeshInstance& meshInstance*/);

	void quit(SDL_AppResult /*no arg name?*/);

	void draw(/*const std::unordered_map<Vec2, Color>& rasteredPixels*/) const;

	/*advances frameCount member var by 1 after frameDelay is reached*/
	void advanceFrame(const std::chrono::steady_clock::time_point& frameStart);
};

