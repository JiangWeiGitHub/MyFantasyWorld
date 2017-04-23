#include "Audio.h"

Audio* Audio::m_instance = nullptr;
Audio* Audio::getInstance()
{
	if(m_instance == nullptr)
	{
		m_instance = new Audio();
	}

	return m_instance;
}

void Audio::playBGM()
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music/music.ogg",true);
}

void Audio::playReadyGo()
{
	SimpleAudioEngine::getInstance()->playEffect("Music/readygo.ogg",false);
}

void Audio::playPop()
{
	SimpleAudioEngine::getInstance()->playEffect("Music/pop.ogg",false);
}

void Audio::playCombo(int size)
{
	if(size < 5)
		return;
	if(size >= 10)
	{
		SimpleAudioEngine::getInstance()->playEffect("Music/combo_3.ogg",false);
	}
	else if(size >= 7)
	{
		SimpleAudioEngine::getInstance()->playEffect("Music/combo_2.ogg",false);
	}
	else
	{
		SimpleAudioEngine::getInstance()->playEffect("Music/combo_1.ogg",false);
	}
}

void Audio::prepare()
{
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/music.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/readygo.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/pop.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/combo_1.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/combo_2.ogg");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/combo_3.ogg");
}
