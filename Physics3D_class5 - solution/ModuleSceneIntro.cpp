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

	s.size = vec3(5, 3, 1);
	s.SetPos(45.0f, 12.5f, 10.0f);

	sensor1 = App->physics->AddBody(s, 0.0f);
	sensor1->SetAsSensor(true);
	sensor1->collision_listeners.add(this);

	s.size = vec3(1, 3, 5);
	s.SetPos(40.0f, 12.5f, 110.0f);

	sensor2 = App->physics->AddBody(s, 0.0f);
	sensor2->SetAsSensor(true);
	sensor2->collision_listeners.add(this);

	s.size = vec3(5, 3, 1);
	s.SetPos(-55.0f, 12.5f, 100.0f);

	sensor3 = App->physics->AddBody(s, 0.0f);
	sensor3->SetAsSensor(true);
	sensor3->collision_listeners.add(this);

	s.size = vec3(1, 3, 5);
	s.SetPos(-45.0f, 12.5f, 0.0f);

	sensor4 = App->physics->AddBody(s, 0.0f);
	sensor4->SetAsSensor(true);
	sensor4->collision_listeners.add(this);

	s.size = vec3(1, 3, 5);
	s.SetPos(40.0f, 12.5f, 0.0f);

	sensor5 = App->physics->AddBody(s, 0.0f);
	sensor5->SetAsSensor(true);
	sensor5->collision_listeners.add(this);



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

	//-------------------Balls----------------------
	ball_1.radius = ball_2.radius = 15;

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

	if (sens1 && sens2 && sens3 && sens4 && sens5)
	{
		win = true;
	}

	if (win)
	{
		
	}

	//sensor1->GetTransform(&s.transform);

	//s.Render();

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

	//------------------quicksand------------------
	Cube quicksand1(70.0f, 10.0f, 5.0f);
	Cube quicksand2(70.0f, 10.0f, 5.0f);
	quicksand1.color = { 255.0f, 255.0f, 0.0f };
	quicksand2.color = { 255.0f, 255.0f, 0.0f };

	//------------------quicksand pos------------------
	quicksand1.SetPos(15.0f, 5.0f, 112.5f);
	quicksand2.SetPos(-15.0f, 5.0f, 107.5f);

	//------------------Render---------------------
	platform.Render();
	platform2.Render();
	platform4.Render();
	platform3_1.Render();
	platform3_2.Render();
	quicksand1.Render();
	quicksand2.Render();

	//-------------------Balls----------------------
	ball_1.SetPos(0.0f + i, 20.0f, 80.0f);
	ball_2.SetPos(0.0f - i, 20.0f, 40.0f);

	if (i == 70.0f && !right)
	{
		right = true;
		left = false;
	}
	if (i == -70.0f && !left)
	{
		right = false;
		left = true;
	}
	if (right)
	{
		i -= 5.0f;
	}
	else if (left)
	{
		i += 5.0f;
	}

	ball_1.color = { 100,100,25 };
	ball_2.color = {0,0,0};
	ball_1.Render();
	ball_2.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body2 == (PhysBody3D*)App->player->vehicle)
	{
		if (body1 == sensor1)
		{
			sens1 = true;
		}
		else if (body1 == sensor2)
		{
			sens2 = true;
		}
		else if (body1 == sensor3)
		{
			sens3 = true;
		}
		else if (body1 == sensor4)
		{
			sens4 = true;
		}
		else if (body1 == sensor5)
		{
			sens5 = true;
		}
	}
}

