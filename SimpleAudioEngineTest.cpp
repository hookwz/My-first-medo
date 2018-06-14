#include"SimpleAudioEngineTest.h"
#include"cocos2d.h"

using namespace cocos2d;

SimpleAudioEngineTest::SimpleAudioEngineTest()
{
	_engine=nullptr;//��ָ������
	_audioID =0 ;
	_loop = false;
}

Scene* SimpleAudioEngineTest::createScene()
{
	auto scene =Scene::create();
	auto layer =SimpleAudioEngineTest::create();
	scene->addChild(layer);
	return scene;
};

bool SimpleAudioEngineTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visible = Director::getInstance()->getVisibleSize();

	auto label1 = Label::createWithSystemFont("SimpleAudioTest", "", 30);
	label1->setPosition(Vec2(visible.width / 2, visible.height - label1->getContentSize().height));
	this->addChild(label1);
	//��������Play�˵�
	//MenuitemFont��ʹ�����嶨��Ĳ˵��FontΪ�������˼
	auto  play_item = MenuItemFont::create("Play", [&](Ref *sender)
	{
		_audioID = _engine->playEffect("music/MARiA - �O�S����.mp3", false, 1.0f, 1.0f);
	});
	play_item->setPosition(Vec2(-visible.width / 4, visible.height / 4));


	//��������Stop�˵�
	auto   stop_item = MenuItemFont::create("Stop", [&](Ref *sender) {
		if (_audioID != 0)
		{
			_engine->stopEffect(_audioID);//�����Ŀʱ������ֹͣ����������Ϊ����ID
			_audioID = 0;
		}
	});
	stop_item->setPosition(Vec2(visible.width / 4, visible.height / 4));
	//����������ͣ�˵���Pause��
	auto  pause_item = MenuItemFont::create("Pause", [&](Ref *sender)
	{
		if (_audioID != 0)
			_engine->pauseEffect(_audioID);
	});
	pause_item->setPosition(Vec2(-visible.width / 4, 0));
	//�������ûָ��˵���resume��
	auto  Resume_item = MenuItemFont::create("Resume", [&](Ref *sender)
	{
		if (_audioID = 0)
		{
			_engine->resumeEffect(_audioID);
		}
	});
	Resume_item->setPosition(Vec2(visible.width / 4, 0));
	auto menu = Menu::create(play_item,pause_item,stop_item,Resume_item,NULL);
	addChild(menu, 10);
	return true;
}


   
	//�������õڶ��˵�ѡ����ǵ��½���AudioEngine����ĵ����������SimpleAudioEngine,���ܹ����������Ĳ��Ž��ȣ������ܹ������������������ƣ�
  void SimpleAudioEngineTest::onenter()//��д��������Ľ��뺯��
	{
	  Layer::onEnter();
	  //���������ʼ��
	  _engine = SimpleAudioEngine::getInstance();
	  //Ԥ��������
	  _engine->preloadEffect("music/MARiA - �O�S����.mp3");

	  CCLOG("OnEnter");
	}
  void   SimpleAudioEngineTest::onexit()
  {
	  if (_engine)
	  {
		  _engine->unloadEffect("music/MARiA - �O�S����.mp3");
	  }
	  Layer::onExit();

  }

