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
	bola = App->textures->Load("pinball/bola.png");
	circles.add(App->physics->CreateCircle(515, 826, 15));
	circles.getLast()->data->listener = this;
	muellesito.add(App->physics->CreateRectangle(515, 850, 30, 20));
	
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
	App->renderer->Blit(bola, x, y, NULL, 1.0f, c->data->GetRotation());
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		position.y--;
		if (position.y >= 530) {
			position.y = 530;
		}
		
	}
	
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP) {
		position.y = 515;
	}

	return UPDATE_CONTINUE;
}