#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;


class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:

	Cube s;

	PhysBody3D* sensor1 = nullptr;
	PhysBody3D* sensor2 = nullptr;
	PhysBody3D* sensor3 = nullptr;
	PhysBody3D* sensor4 = nullptr;
	PhysBody3D* sensor5 = nullptr;

	bool sens1 = false;
	bool sens2 = false;
	bool sens3 = false;
	bool sens4 = false;
	bool sens5 = false;

	bool win = false;

	Sphere ball_1;
	Sphere ball_2;

	int i=0.0f;
	bool left = true, right = false;

};
