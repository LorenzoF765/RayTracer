#include"Renderer.h"
#include"Sphere.h"
#include<iostream>


int main(int,char**){
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(800,400);

	Canvas canvas(800, 400, renderer);
	auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, nullptr);


	bool quit=false;
	while(!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
			quit=true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}
		//canvas.Clear({ 0, 0, 0, 1 });
		renderer.Render(canvas, sphere.get());
		//canvas.Update();
		
		
		//for (int i = 0; i < 26746; i++) {

		//	canvas.DrawPoint({ random(0, 420), random(0, 690) }, { 1, 1, 1, 1 });
		//	canvas.DrawPoint({ random(0, 420), random(0, 690) }, { 0, 0, 1, 1 });
		//	canvas.DrawPoint({ random(0, 420), random(0, 690) }, { 1, 0, 0, 1 });
		//	canvas.DrawPoint({ random(0, 420), random(0, 690) }, { 0, 1, 0, 1 });
		//}
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}
	renderer.Shutdown();
	return 0;
}