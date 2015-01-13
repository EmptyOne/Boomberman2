// EndState.cpp

//Inte riktigt s�ker p� vad vi beh�ver ta med atm
#include "stdafx.h"
#include "EndState.h"
#include "GameState.h"
#include "MenuState.h"

#include "Mouse.h"
#include "Keyboard.h"
#include "InputManager.h"

#include "DrawManager.h"
#include "SpriteManager.h"
#include "Sprite.h"


#include "SoundManager.h"
#include "SoundClip.h"

#include "UI.h"

#include <fstream>
#include <iostream>


EndState::EndState(System& system)
{
	m_systems = system;

	std::string win = "../assets/win.wav";

	SoundClip* victory = m_systems.sound_manager->CreateSoundClip(win);
	victory->Play();

	std::string twowinimg = "../assets/endstatetwo.png";
	Sprite* sprite;


	sprite = m_systems.sprite_manager->CreateSprite(twowinimg, 0, 0, 1080, 832);
	UI* twowin = new UI(sprite, 0, 0);
	twowin->SetType(5);
	m_entities.push_back(twowin);

	std::cout << "endstate" << std::endl;

	m_active = false;


}

EndState::~EndState()
{

}

bool EndState::Update(float deltatime)
{
	Keyboard* m_keyboard;
	if (m_systems.input_manager->GetKeyboard()->IsKeyDown(SDLK_y) == true){
		std::cout << "y" << std::endl;

		std::string woho = "../assets/woho.wav";

		SoundClip* restart = m_systems.sound_manager->CreateSoundClip(woho);
		restart->Play();

		m_state = true;
		NextState();
		return false;
		
	}
	else if (m_systems.input_manager->GetKeyboard()->IsKeyDown(SDLK_n) == true){
		std::cout << "n" << std::endl;
		m_state = false;
		NextState();
		return false;
		
	}
	else
		return true;
}

void EndState::Draw()
{
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsVisible())
			continue;

		Sprite* sprite = m_entities[i]->GetSprite();
		if (sprite)
		{
			m_systems.draw_manager->Draw(sprite,
				m_entities[i]->GetX(),
				m_entities[i]->GetY());
		}
	}
}

State* EndState::NextState()
{
	if (m_state == true){

		return new GameState(m_systems);
	}
	else if (m_state == false){

		return new MenuState(m_systems);
	}

}

void EndState::CollisionChecking()
{

}