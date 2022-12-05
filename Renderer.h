#pragma once
#include<SDL.h>
#include "Canvas.h"
#include "Ray.h"
class Renderer{ 
public:
	Renderer() = default; 
	bool Initialize(); 
	void Shutdown(); 
	bool CreateWindow(int width,int height); 

	void CopyCanvas(const Canvas& canvas);
	void Present();

	friend class Canvas;

	void Render(Canvas& canvas);

private:
	color3 GetBackgroundFromRay(const Ray& ray);
	SDL_Window * m_window{nullptr}; 
	   SDL_Renderer * m_renderer{nullptr}; 
};