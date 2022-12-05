#include"Renderer.h"
#include<iostream>
#include <SDL.h>

bool Renderer::Initialize() 
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		std::cout << "SDLError:" << SDL_GetError() << std::endl; return false; 
	}return true; 
}
void Renderer::Shutdown() 
{ 
	if (m_window)SDL_DestroyWindow(m_window); if (m_renderer)SDL_DestroyRenderer(m_renderer); SDL_Quit(); 
}
bool Renderer::CreateWindow(int width, int height) 
{ 
	m_window = SDL_CreateWindow("2DRenderer", 100, 100, width, height, SDL_WINDOW_SHOWN); if (m_window == nullptr) 
	{ std::cout << "SDLError:" << SDL_GetError() << std::endl; SDL_Quit(); return false;
	}m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); if (m_renderer == nullptr) { std::cout << "SDLError:" << SDL_GetError() << std::endl; return false; 
	
	}
	return true; 
}

void Renderer::CopyCanvas(const Canvas& canvas) {
	SDL_RenderCopy(m_renderer, canvas.m_texture, nullptr, nullptr);
}

void Renderer::Present()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::Render(Canvas& canvas)
{
	glm::vec3 lowerLeft{ -2, -1, -1 };
	glm::vec3 eye{ 0, 0, 0 };
	glm::vec3 right{ 4, 0, 0 };
	glm::vec3 up{ 0, 2, 0 };

	for (int y = 0; y < canvas.GetHeight(); y++)
	{
		for (int x = 0; x < canvas.GetWidth(); x++)
		{
			float u = x / (float)canvas.GetWidth();
			float v = 1 - (y / (float)canvas.GetHeight());

			glm::vec3 direction = lowerLeft + (u * right) + (v * up);
			Ray ray{ eye, direction };

			color3 color = GetBackgroundFromRay(ray);
			canvas.DrawPoint({ x, y }, color4(color, 1));
		}
	}
}
color3 Renderer::GetBackgroundFromRay(const Ray& ray)
{
	glm::vec3 direction = glm::normalize(ray.direction);
	float t = 0.5f * (direction.y + 1.0f);

	return interp(color3{ 1.0f }, color3{ 0.5f, 0.7f, 1.0f }, t);
}