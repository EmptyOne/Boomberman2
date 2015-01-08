// Playerone.h

#pragma once

#include "Entity.h"


class Explosion : public Entity
{
public:
	
	Explosion(Sprite* sprite, float x, float y);
	~Explosion();

	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();
	float GetDir();
	void SetY(float y);
	void SetX(float x);


	void Reset();

	bool IsVisible();
	bool IsActive();
	EEntityType GetType();
	Collider* GetCollider();


private:
	Sprite* m_sprite;
	Collider* m_collider;

	float m_x;
	float m_y;
	float m_dir;


	
	float m_playerSpeed;
	float m_bombSpeed;

	float m_explosionTimer;

	bool m_active;


};

