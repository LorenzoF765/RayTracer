#pragma once
#include<SDL.h>
#include "Canvas.h"
#include "Ray.h"
#include "Object.h"
class Renderer{ 
public:
	Renderer() = default; 
	bool Initialize(); 
	void Shutdown(); 
	bool CreateWindow(int width,int height); 

	void CopyCanvas(const Canvas& canvas);
	void Present();

	friend class Canvas;

	void Render(Canvas& canvas, Object* object);

private:
	color3 GetBackgroundFromRay(const Ray& ray);
	SDL_Window * m_window{nullptr}; 
	   SDL_Renderer * m_renderer{nullptr}; 
};