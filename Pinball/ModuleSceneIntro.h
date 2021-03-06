#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void map();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;
	p2List<PhysBody*> elephs;
	p2List<PhysBody*> walls;
	p2List<PhysBody*> wal1;
	PhysBody* sensor;
	PhysBody* right;
	PhysBody* right_circle;
	PhysBody* left;
	PhysBody* left_circle;
	
	bool sensed;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	SDL_Texture* background;
	SDL_Texture* elephant;
	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on=true;
};
