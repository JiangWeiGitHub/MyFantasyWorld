#include "./Background.h"

namespace jiangweigithub {

  cocos2d::Layer* BackgroundLayer::getBackgroundLayer()
  {
    auto tmp = BackgroundLayer::create();

    return tmp;
  }

  bool BackgroundLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    jiangweigithub::Database* systemData = jiangweigithub::Database::getDatabaseInstance();
    std::map<std::string, std::string> databaseData;
    systemData->runSQL("SELECT musicVolume,bgmVolume,subtitle FROM system", (void *)(&databaseData));

    std::map<std::string, std::string>::iterator iter;  
    for(iter = databaseData.begin(); iter != databaseData.end(); iter++)
    {
      if(iter->first == "musicVolume")
      {
        std::istringstream iss(iter->second);  
        iss >> _musicVolume;  
      }
      else if(iter->first == "bgmVolume")
      {
        std::istringstream iss(iter->second);  
        iss >> _bgmVolume;  
      }
      else if(iter->first == "subtitle")
      {
        std::istringstream iss(iter->second);  
        iss >> _language;  
      }
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto backPic = cocos2d::Sprite::create("config_background.jpg");
    backPic->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(backPic, 0);

    if(_language == 0)
    {
      auto title = cocos2d::Label::createWithTTF("Configuration", "fonts/MSYH.TTF", 30);
      // auto title = cocos2d::Label::createWithTTF("Configuration", "fonts/MSYH.TTF", 30);
      title->setTextColor(cocos2d::Color4B(255,255,255,200));
      title->enableShadow();
      title->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 250));
      this->addChild(title, 1);

    }
    else if(_language == 1)
    {
      auto title = cocos2d::Label::createWithTTF("配置", "fonts/MSYHBD.TTF", 30);
      // auto title = cocos2d::Label::createWithTTF("Configuration", "fonts/MSYH.TTF", 30);
      title->setTextColor(cocos2d::Color4B(255,255,255,200));
      title->enableShadow();
      title->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 250));
      this->addChild(title, 1);
    }

    // this->scheduleUpdate();

    if(_language == 0)
    {
      // auto musicTitle = cocos2d::ui::Text::create("Music Volume","fonts/MSYH.TTF",24);
      // musicTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 120));
      // this->addChild(musicTitle);

      auto musicTitle = cocos2d::Label::createWithTTF("Music Volume", "fonts/MSYH.TTF", 24);
      musicTitle->enableBold();
      musicTitle->setAdditionalKerning(1);
      musicTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 120));

      this->addChild(musicTitle);
    }
    else if(_language == 1)
    {
      // auto musicTitle = cocos2d::ui::Text::create("音效音量","fonts/MSYH.TTF",24);
      // musicTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 120));
      // this->addChild(musicTitle);

      auto musicTitle = cocos2d::Label::createWithTTF("音效音量", "fonts/MSYH.TTF", 24);
      musicTitle->enableBold();
      musicTitle->setAdditionalKerning(1);
      musicTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 120));

      this->addChild(musicTitle);
    }

    _musicSlider = cocos2d::ui::Slider::create();
    _musicSlider->loadBarTexture("sliderTrack.png");
    _musicSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    _musicSlider->loadProgressBarTexture("sliderProgress.png");
    _musicSlider->setPercent(_musicVolume);
    _musicSlider->setMaxPercent(100);
    _musicSlider->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 120));
    _musicSlider->addEventListener(CC_CALLBACK_2(BackgroundLayer::_musicVolumeEvent, this));
    this->addChild(_musicSlider);

    // _musicVolumeLabel = cocos2d::ui::Text::create(std::to_string(_musicVolume),"fonts/MSYH.TTF",24);
    _musicVolumeLabel = cocos2d::Label::createWithTTF(std::to_string(_musicVolume),"fonts/MSYH.TTF",24);
    _musicVolumeLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 + 120));
    this->addChild(_musicVolumeLabel);


    if(_language == 0)
    {
      // auto BGMTitle = cocos2d::ui::Text::create("BGM Volume","fonts/MSYH.TTF",24);
      // BGMTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 50));
      // this->addChild(BGMTitle);

      auto BGMTitle = cocos2d::Label::createWithTTF("BGM Volume", "fonts/MSYH.TTF", 24);
      BGMTitle->enableBold();
      BGMTitle->setAdditionalKerning(1);
      BGMTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 50));

      this->addChild(BGMTitle);
    }
    else if(_language == 1)
    {
      // auto BGMTitle = cocos2d::ui::Text::create("背景音音量","fonts/MSYH.TTF",24);
      // BGMTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 50));
      // this->addChild(BGMTitle);

      auto BGMTitle = cocos2d::Label::createWithTTF("背景音音量", "fonts/MSYH.TTF", 24);
      BGMTitle->enableBold();
      BGMTitle->setAdditionalKerning(1);
      BGMTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 50));

      this->addChild(BGMTitle);
    }

    _bgmSlider = cocos2d::ui::Slider::create();
    _bgmSlider->loadBarTexture("sliderTrack.png");
    _bgmSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    _bgmSlider->loadProgressBarTexture("sliderProgress.png");
    _bgmSlider->setPercent(_bgmVolume);
    _bgmSlider->setMaxPercent(100);
    _bgmSlider->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
    _bgmSlider->addEventListener(CC_CALLBACK_2(BackgroundLayer::_BGMVolumeEvent, this));
    this->addChild(_bgmSlider);

    // _bgmVolumeLabel = cocos2d::ui::Text::create(std::to_string(_bgmVolume),"fonts/MSYH.TTF",24);
    _bgmVolumeLabel = cocos2d::Label::createWithTTF(std::to_string(_bgmVolume),"fonts/MSYH.TTF",24);
    _bgmVolumeLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 + 50));
    this->addChild(_bgmVolumeLabel);

    if(_language == 0)
    {
      // auto subTitle = cocos2d::ui::Text::create("Language","fonts/MSYH.TTF",24);
      // subTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 20));
      // this->addChild(subTitle);

      auto subTitle = cocos2d::Label::createWithTTF("Language", "fonts/MSYH.TTF", 24);
      subTitle->enableBold();
      subTitle->setAdditionalKerning(1);
      subTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 55));

      this->addChild(subTitle);
    }
    else if(_language == 1)
    {
      // auto subTitle = cocos2d::ui::Text::create("语言","fonts/MSYH.TTF",24);
      // subTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 20));
      // this->addChild(subTitle);

      auto subTitle = cocos2d::Label::createWithTTF("语言", "fonts/MSYH.TTF", 24);
      subTitle->enableBold();
      subTitle->setAdditionalKerning(1);
      subTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 55));

      this->addChild(subTitle);
    }

    _languageEnglishCheckBox = cocos2d::ui::CheckBox::create("check_box_normal.png",
                                                        "check_box_normal_press.png",
                                                        "check_box_active.png",
                                                        "check_box_normal_disable.png",
                                                        "check_box_active_disable.png");
    _languageEnglishCheckBox->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 20));
    if(_language == 0)
    {
      _languageEnglishCheckBox->setSelected(true);
      _languageEnglishCheckBox->addEventListener(CC_CALLBACK_2(BackgroundLayer::_selectedEnglishCheckBoxEvent, this));
      this->addChild(_languageEnglishCheckBox);
    }
    else
    {
      _languageEnglishCheckBox->setSelected(false);
      _languageEnglishCheckBox->addEventListener(CC_CALLBACK_2(BackgroundLayer::_selectedEnglishCheckBoxEvent, this));
      this->addChild(_languageEnglishCheckBox);
    }
    
    // if(_language == 0)
    // {
    //   _englishLabel = cocos2d::ui::Text::create("中文","fonts/MSYH.TTF",24);
    // }
    // else
    // {
    //   _englishLabel = cocos2d::ui::Text::create("English","fonts/MSYH.TTF",24);
    // }
    
    // _englishLabel = cocos2d::ui::Text::create("English","fonts/MSYH.TTF",24);
    _englishLabel = cocos2d::Label::createWithTTF("English","fonts/MSYH.TTF",24);
    _englishLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 20));
    this->addChild(_englishLabel);


    _languageChineseCheckBox = cocos2d::ui::CheckBox::create("check_box_normal.png",
                                                        "check_box_normal_press.png",
                                                        "check_box_active.png",
                                                        "check_box_normal_disable.png",
                                                        "check_box_active_disable.png");
    _languageChineseCheckBox->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 90));
    if(_language == 0)
    {
      _languageChineseCheckBox->setSelected(false);
      _languageChineseCheckBox->addEventListener(CC_CALLBACK_2(BackgroundLayer::_selectedChineseCheckBoxEvent, this));
      this->addChild(_languageChineseCheckBox);
    }
    else
    {
      _languageChineseCheckBox->setSelected(true);
      _languageChineseCheckBox->addEventListener(CC_CALLBACK_2(BackgroundLayer::_selectedChineseCheckBoxEvent, this));
      this->addChild(_languageChineseCheckBox);
    }
    
    // _chineseLabel = cocos2d::ui::Text::create("中文","fonts/MSYH.TTF",24);
    _chineseLabel = cocos2d::Label::createWithTTF("中文","fonts/MSYH.TTF",24);
    _chineseLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 90));
    this->addChild(_chineseLabel);


    auto saveButton = cocos2d::ui::Button::create("animationbuttonnormal.png",
                                          "animationbuttonpressed.png");
    saveButton->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 150, visibleSize.height / 2 - 220));
    saveButton->addTouchEventListener(CC_CALLBACK_2(BackgroundLayer::_saveButtonEvent, this));
    saveButton->setTitleText("Save");
    saveButton->setTitleFontSize(19);
    saveButton->setZoomScale(0.1f);
    saveButton->setOpacity(255);
    saveButton->setPressedActionEnabled(true);
    this->addChild(saveButton);

    auto resetButton = cocos2d::ui::Button::create("animationbuttonnormal.png",
                                          "animationbuttonpressed.png");
    resetButton->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 220));
    resetButton->addTouchEventListener(CC_CALLBACK_2(BackgroundLayer::_resetButtonEvent, this));
    resetButton->setTitleText("Reset");
    resetButton->setTitleFontSize(19);
    resetButton->setZoomScale(0.1f);
    resetButton->setOpacity(255);
    resetButton->setPressedActionEnabled(true);
    this->addChild(resetButton);

    auto backButton = cocos2d::ui::Button::create("animationbuttonnormal.png",
                                          "animationbuttonpressed.png");
    backButton->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 150, visibleSize.height / 2 - 220));
    backButton->addTouchEventListener(CC_CALLBACK_2(BackgroundLayer::_backButtonEvent, this));
    backButton->setTitleText("Back");
    backButton->setTitleFontSize(19);
    backButton->setZoomScale(0.1f);
    backButton->setOpacity(255);
    backButton->setPressedActionEnabled(true);
    this->addChild(backButton);

    return true;  
  }

  void BackgroundLayer::_musicVolumeEvent(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type)
  {
    if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
      cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(pSender);
      _musicVolume = slider->getPercent();
      int maxPercent = slider->getMaxPercent();
      _musicVolumeLabel->setString(cocos2d::StringUtils::format("%d", 100 * _musicVolume / maxPercent));
    }
  }

  void BackgroundLayer::_BGMVolumeEvent(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type)
  {
    if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
      cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(pSender);
      _bgmVolume = slider->getPercent();
      int maxPercent = slider->getMaxPercent();
      _bgmVolumeLabel->setString(cocos2d::StringUtils::format("%d", 100 * _bgmVolume / maxPercent));

      jiangweigithub::Director::setBackgroundMusicVolume(_bgmVolume);
    }
  }

  void BackgroundLayer::_selectedEnglishCheckBoxEvent(cocos2d::Ref* pSender,cocos2d::ui::CheckBox::EventType type)
  {
    switch (type)
    {
      case cocos2d::ui::CheckBox::EventType::SELECTED:
        _language = 0;
        _languageEnglishCheckBox->setSelected(true);
        _languageChineseCheckBox->setSelected(false);
        break;
          
      case cocos2d::ui::CheckBox::EventType::UNSELECTED:
        _language = 1;
        _languageEnglishCheckBox->setSelected(false);
        _languageChineseCheckBox->setSelected(true);
        break;
          
      default:
        break;
    }      
  }

  void BackgroundLayer::_selectedChineseCheckBoxEvent(cocos2d::Ref* pSender,cocos2d::ui::CheckBox::EventType type)
  {
    switch (type)
    {
      case cocos2d::ui::CheckBox::EventType::SELECTED:
        _language = 1;
        _languageEnglishCheckBox->setSelected(false);
        _languageChineseCheckBox->setSelected(true);
        break;
          
      case cocos2d::ui::CheckBox::EventType::UNSELECTED:
        _language = 0;
        _languageEnglishCheckBox->setSelected(true);
        _languageChineseCheckBox->setSelected(false);
        break;
          
      default:
        break;
    }      
  }

  void BackgroundLayer::_saveButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type)
  {
    if(type == cocos2d::ui::Widget::TouchEventType::BEGAN)
    {

    }
    else if(type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
      jiangweigithub::Director::playEffectMusic("music/effect/Cartoon Weird Noise Short Lip Smack 01.wav");

      std::map<std::string, std::string> returnResult;
      std::map<std::string, std::string>::iterator iter;
      jiangweigithub::Database* aaa = jiangweigithub::Database::getDatabaseInstance();

      std::string tmp = "UPDATE system SET bgmVolume=" + std::to_string(_bgmVolume) + ",musicVolume=" + std::to_string(_musicVolume) + ",subtitle=" + std::to_string(_language);
      std::cout<<tmp<<std::endl;
      aaa->runSQL(tmp, (void *)(&returnResult));
      for(iter = returnResult.begin(); iter != returnResult.end(); iter++)
      {
        std::cout<<iter->first<<' '<<iter->second<<std::endl;
      }
    }
    else
    {

    }  
  }

  void BackgroundLayer::_resetButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type)
  {
    if(type == cocos2d::ui::Widget::TouchEventType::BEGAN)
    {

    }
    else if(type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
      jiangweigithub::Director::playEffectMusic("music/effect/Cartoon Weird Noise Short Lip Smack 01.wav");

      std::map<std::string, std::string> returnResult;
      std::map<std::string, std::string>::iterator iter;
      jiangweigithub::Database* tmpSQLite = jiangweigithub::Database::getDatabaseInstance();

      std::string tmp = "SELECT musicVolume,bgmVolume,subtitle FROM system";
      std::cout<<tmp<<std::endl;
      tmpSQLite->runSQL(tmp, (void *)(&returnResult));
      for(iter = returnResult.begin(); iter != returnResult.end(); iter++)
      {
        // std::cout<<iter->first<<' '<<iter->second<<std::endl;
        if(iter->first == "musicVolume")
        {
          std::istringstream iss(iter->second);
          iss >> _musicVolume;

          _musicSlider->setPercent(_musicVolume);
          _musicVolumeLabel->setString(cocos2d::StringUtils::format("%d", _musicVolume));
        }
        else if(iter->first == "bgmVolume")
        {
          std::istringstream iss(iter->second);  
          iss >> _bgmVolume;

          _bgmSlider->setPercent(_bgmVolume);
          _bgmVolumeLabel->setString(cocos2d::StringUtils::format("%d", _bgmVolume));
        }
        else if(iter->first == "subtitle")
        {
          std::istringstream iss(iter->second);  
          iss >> _language;

          if(_language == 1)
          {
            _languageEnglishCheckBox->setSelected(true);
            _englishLabel->setString(cocos2d::StringUtils::format("On"));
          }
          else
          {
            _languageEnglishCheckBox->setSelected(false);
            _englishLabel->setString(cocos2d::StringUtils::format("Off"));
          }
        }
      }
    }
    else
    {

    }     
  }

  void BackgroundLayer::_backButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type)
  {
    switch (type)
    {
      case cocos2d::ui::Widget::TouchEventType::BEGAN:
        break;  
      case cocos2d::ui::Widget::TouchEventType::ENDED:
      {
        jiangweigithub::Director::playEffectMusic("music/effect/Cartoon Weird Noise Short Lip Smack 01.wav");
        
        auto loginScene = jiangweigithub::LoginScene::getLoginScene();
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(DEFAULT_SWITCH_TRANSITION / 2, loginScene, cocos2d::Color3B(0,0,0)));
      }
        break;
      default:
        break;
    }     
  }

  void BackgroundLayer::update(float delta)
  {

  }

  // void BackgroundLayer::_gotoHomeScene()
  // {
  //   auto homeScene = jiangweigithub::HomeScene::getHomeScene();
  //   cocos2d::Director::getInstance()->replaceScene(homeScene);
  // }

}