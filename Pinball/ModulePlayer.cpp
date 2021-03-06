#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModulePhysics.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	//Textures
	bola = App->textures->Load("pinball/bola.png");
	//Rectangles and Circle
	circles.add(App->physics->CreateCircle(515, 826, 15));
	circles.getLast()->data->listener = this;
	muellesito=App->physics->CreateRectangle(515, 850, 30, 20);
	/*StacticMuelle = App->physics->CreateRectangle(515, 930, 30, 20);
	StacticMuelle->body->SetType(b2_staticBody);*/
	

	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	p2List_item<PhysBody*>* c = circles.getFirst();
	int x, y;
	c->data->GetPosition(x, y);
	static int pow = 0;
	App->renderer->Blit(bola, x, y, NULL, 1.0f, c->data->GetRotation());

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		pow += 40;
		if (pow > 300)
			pow = 300;
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		
		muellesito->body->ApplyForceToCenter(b2Vec2(0, -pow), 1);
		
	}
	
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP) {
		position.y = 515;
	}

	/*b2DistanceJointDef MuelleJoint;
	MuelleJoint.bodyA = muellesito->body;
	MuelleJoint.bodyB = StacticMuelle->body;*/

	return UPDATE_CONTINUE;
}