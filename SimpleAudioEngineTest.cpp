#include"SimpleAudioEngineTest.h"
#include"cocos2d.h"

using namespace cocos2d;

SimpleAudioEngineTest::SimpleAudioEngineTest()
{
	_engine=nullptr;//空指针类型
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
	//用于设置Play菜单
	//MenuitemFont是使用字体定义的菜单项，Font为字体的意思
	auto  play_item = MenuItemFont::create("Play", [&](Ref *sender)
	{
		_audioID = _engine->playEffect("music/MARiA - 極楽浄土.mp3", false, 1.0f, 1.0f);
	});
	play_item->setPosition(Vec2(-visible.width / 4, visible.height / 4));


	//用于设置Stop菜单
	auto   stop_item = MenuItemFont::create("Stop", [&](Ref *sender) {
		if (_audioID != 0)
		{
			_engine->stopEffect(_audioID);//点击条目时，调用停止函数，参数为音乐ID
			_audioID = 0;
		}
	});
	stop_item->setPosition(Vec2(visible.width / 4, visible.height / 4));
	//用于设置暂停菜单（Pause）
	auto  pause_item = MenuItemFont::create("Pause", [&](Ref *sender)
	{
		if (_audioID != 0)
			_engine->pauseEffect(_audioID);
	});
	pause_item->setPosition(Vec2(-visible.width / 4, 0));
	//用于设置恢复菜单（resume）
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


   
	//用于设置第二菜单选项（这是等下进入AudioEngine引擎的点击，它比起SimpleAudioEngine,还能够控制声音的播放进度，并且能够控制声音的音量控制）
  void SimpleAudioEngineTest::onenter()//重写声音引擎的进入函数
	{
	  Layer::onEnter();
	  //声音引擎初始化
	  _engine = SimpleAudioEngine::getInstance();
	  //预加载声音
	  _engine->preloadEffect("music/MARiA - 極楽浄土.mp3");

	  CCLOG("OnEnter");
	}
  void   SimpleAudioEngineTest::onexit()
  {
	  if (_engine)
	  {
		  _engine->unloadEffect("music/MARiA - 極楽浄土.mp3");
	  }
	  Layer::onExit();

  }

