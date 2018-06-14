#pragma once
#ifndef __SIMPLE_AUDIO_ENGINE_TEST_H__ 
#define __SIMPLE_AUDIO_ENGINE_TEST_H__ 
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;//������������������ռ�

class  SimpleAudioEngineTest:public Layer
{
 public:
	 SimpleAudioEngineTest();
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(SimpleAudioEngineTest);

	virtual void onenter();//��дonEnter�ķ���
	virtual void onexit();//��дonExit�ķ���
private:
	//����Ҫ�Ķ����������浥ָ��
	SimpleAudioEngine * _engine;
 	unsigned int _audioID;//�����ļ�ID
	bool _loop;//�Ƿ�ѭ������

};
#endif