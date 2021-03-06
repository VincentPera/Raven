#pragma once
#ifndef TEAM_SIMPLE_H
#define TEAM_SIMPLE_H
#include <vector>
#include <iosfwd>
#include <map>
#include <list>

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "Raven_TargetingSystem.h"

class Raven_Bot;
class TeamSimple
{
private : 
	Vector2D				lootingLocation; //Location where memeber of this team drop their weapon hen they died
	std::list<Raven_Bot*>	members;
	Raven_Bot*				target;
	std::string				name_team;
	Raven_Bot*				team_leader;

	//this holds a number of spawn positions of the team.
	// Members of the team will respawn here
	std::vector<Vector2D>   m_SpawnPoints;

public:
	// Constructors
	TeamSimple();
	TeamSimple(Vector2D lootingLocation, std::string name);

	// Methods
	void							UpdateNewTarget(Raven_Bot* bot, int id_sender);
	Raven_Bot*						GetTarget() { return target; }
	void							ClearTarget(int id_sender);
	std::string						GetName() { return name_team; }
	void							Addmember(Raven_Bot* new_memeber);
	Raven_Bot*						GetTeamLeader() { return team_leader; }
	void							AddTeamLeader(Raven_Bot* leader) { team_leader = leader; }

	// Control Spawning points
	void							AddSpawnPoint(Vector2D spawnPoint);
	const std::vector<Vector2D>&	GetSpawnPoints()const { return m_SpawnPoints; }
	Vector2D                        GetRandomSpawnPoint() { return m_SpawnPoints[RandInt(0, m_SpawnPoints.size() - 1)]; }
	Vector2D                        GetLootingLocation() {return lootingLocation;}

	// Destructor
	~TeamSimple();

};
#endif
