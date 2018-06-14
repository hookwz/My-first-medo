#pragma once
#ifndef __SIMPLE_AUDIO_ENGINE_TEST_H__ 
#define __SIMPLE_AUDIO_ENGINE_TEST_H__ 
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;//这是声音引擎的命名空间

class  SimpleAudioEngineTest:public Layer
{
 public:
	 SimpleAudioEngineTest();
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(SimpleAudioEngineTest);

	virtual void onenter();//重写onEnter的方法
	virtual void onexit();//重写onExit的方法
private:
	//最重要的定义声音引擎单指针
	SimpleAudioEngine * _engine;
 	unsigned int _audioID;//声音文件ID
	bool _loop;//是否循环播放

};
#endif