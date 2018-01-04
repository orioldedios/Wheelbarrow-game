#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;


	//--------------------floor platforms-----------
	Cube platform1(100.0f, 10.0f, 10.0f);
	Cube platform2(10.0f, 10.0f, 100.0f);
	Cube platform3_1(70.0f, 10.0f, 5.0f);
	Cube platform3_2(70.0f, 10.0f, 5.0f);
	Cube platform4(10.0f, 10.0f, 120.0f);

	//-------------------floor set pos--------------
	platform1.SetPos(0.0f, 5.0f, 0.0f);
	platform2.SetPos(45.0f, 5.0f, 55.0f);
	platform3_1.SetPos(15.0f, 5.0f, 107.5f);
	platform3_2.SetPos(-15.0f, 5.0f, 112.5f);
	platform4.SetPos(-55.0f, 5.0f, 55.0f);

	App->physics->AddBody(platform1,2000.0f);
	App->physics->AddBody(platform2, 2000.0f);
	App->physics->AddBody(platform3_1, 2000.0f);
	App->physics->AddBody(platform3_2, 2000.0f);
	App->physics->AddBody(platform4, 2000.0f);


	App->camera->Move(vec3(45.0f, 20.0f, -20.0f));
	App->camera->LookAt(vec3(40, 0, 40));

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//--------------------floor platforms-----------
	Cube platform(100.0f, 10.0f, 10.0f);
	Cube platform2(10.0f, 10.0f, 100.0f);
	Cube platform3_1(70.0f, 10.0f, 5.0f);
	Cube platform3_2(70.0f, 10.0f, 5.0f);
	Cube platform4(10.0f, 10.0f, 120.0f);

	//-------------------floor set pos--------------
	platform.SetPos(0.0f, 5.0f, 0.0f);
	platform2.SetPos(45.0f, 5.0f, 55.0f);
	platform3_1.SetPos(15.0f, 5.0f, 107.5f);
	platform3_2.SetPos(-15.0f, 5.0f, 112.5f);
	platform4.SetPos(-55.0f, 5.0f, 55.0f);

	//------------------Render---------------------
	platform.Render();
	platform2.Render();
	platform4.Render();
	platform3_1.Render();
	platform3_2.Render();


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

