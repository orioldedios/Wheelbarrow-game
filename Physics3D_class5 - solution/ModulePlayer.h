#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	update_status PostUpdate(float dt);
	void CreateCar();
	bool CleanUp();

public:

	float* transform = new float[20];
	float* original_transform = new float[20];
	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;

	int death_count = 0;

	mat4x4 matrix;
	vec3 position;
	vec3 cameraPos;
};