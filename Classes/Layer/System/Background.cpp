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
    // systemData->openDatabase();
    std::map<std::string, std::string> databaseData;
    systemData->runSQL("select * from system", databaseData);
    // systemData->closeDatabase();

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto backPic = cocos2d::Sprite::create("config_background.jpg");
    backPic->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(backPic, 0);

    auto title = cocos2d::Label::createWithTTF("Configuration", "fonts/MSYHBD.TTF", 30);
    title->setTextColor(cocos2d::Color4B(255,255,255,200));
    title->enableShadow();
    title->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 250));
    this->addChild(title, 1);

    // this->scheduleUpdate();

    auto musicTitle = cocos2d::ui::Text::create("Music Volume","fonts/MSYHBD.ttf",24);
    musicTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 120));
    this->addChild(musicTitle);

    auto musicSlider = cocos2d::ui::Slider::create();
    musicSlider->loadBarTexture("sliderTrack.png");
    musicSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    musicSlider->loadProgressBarTexture("sliderProgress.png");
    musicSlider->setPercent(50);
    musicSlider->setMaxPercent(100);
    musicSlider->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 120));
    musicSlider->addEventListener(CC_CALLBACK_2(BackgroundLayer::_musicVolumeEvent, this));
    this->addChild(musicSlider);

    _musicVolumeLabel = cocos2d::ui::Text::create("50","fonts/MSYHBD.ttf",24);
    _musicVolumeLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 + 120));
    this->addChild(_musicVolumeLabel);

    auto BGMTitle = cocos2d::ui::Text::create("BGM Volume","fonts/MSYHBD.ttf",24);
    BGMTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 + 50));
    this->addChild(BGMTitle);

    auto BGMSlider = cocos2d::ui::Slider::create();
    BGMSlider->loadBarTexture("sliderTrack.png");
    BGMSlider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png", "");
    BGMSlider->loadProgressBarTexture("sliderProgress.png");
    BGMSlider->setPercent(50);
    BGMSlider->setMaxPercent(100);
    BGMSlider->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
    BGMSlider->addEventListener(CC_CALLBACK_2(BackgroundLayer::_BGMVolumeEvent, this));
    this->addChild(BGMSlider);

    _BGMVolumeLabel = cocos2d::ui::Text::create("50","fonts/MSYHBD.ttf",24);
    _BGMVolumeLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 + 50));
    this->addChild(_BGMVolumeLabel);

    auto subTitle = cocos2d::ui::Text::create("Subtitle","fonts/MSYHBD.ttf",24);
    subTitle->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 20));
    this->addChild(subTitle);

    auto _subCheckBox = cocos2d::ui::CheckBox::create("check_box_normal.png",
                                                        "check_box_normal_press.png",
                                                        "check_box_active.png",
                                                        "check_box_normal_disable.png",
                                                        "check_box_active_disable.png");
    _subCheckBox->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2 - 20));
    _subCheckBox->setSelected(true);
    _subCheckBox->addEventListener(CC_CALLBACK_2(BackgroundLayer::_selectedSubCheckBoxEvent, this));
    this->addChild(_subCheckBox);

    _subLabel = cocos2d::ui::Text::create("On","fonts/MSYHBD.ttf",24);
    _subLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 20));
    this->addChild(_subLabel);


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
      int percent = slider->getPercent();
      int maxPercent = slider->getMaxPercent();
      _musicVolumeLabel->setString(cocos2d::StringUtils::format("%d", 100 * percent / maxPercent));
    }
  }

  void BackgroundLayer::_BGMVolumeEvent(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type)
  {
    if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
      cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(pSender);
      int percent = slider->getPercent();
      int maxPercent = slider->getMaxPercent();
      _BGMVolumeLabel->setString(cocos2d::StringUtils::format("%d", 100 * percent / maxPercent));
    }
  }

  void BackgroundLayer::_selectedSubCheckBoxEvent(cocos2d::Ref* pSender,cocos2d::ui::CheckBox::EventType type)
  {
    switch (type)
    {
      case cocos2d::ui::CheckBox::EventType::SELECTED:
        _subLabel->setString(cocos2d::StringUtils::format("On"));
        break;
          
      case cocos2d::ui::CheckBox::EventType::UNSELECTED:
        _subLabel->setString(cocos2d::StringUtils::format("Off"));
        break;
          
      default:
        break;
    }      
  }

  void BackgroundLayer::_saveButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type)
  {
    switch (type)
    {
      case cocos2d::ui::Widget::TouchEventType::BEGAN:
        break;  
      case cocos2d::ui::Widget::TouchEventType::ENDED:
        std::cout << "Button Save clicked" << std::endl;
        break;
      default:
        break;
    }     
  }

  void BackgroundLayer::_resetButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type)
  {
    switch (type)
    {
      case cocos2d::ui::Widget::TouchEventType::BEGAN:
        break;  
      case cocos2d::ui::Widget::TouchEventType::ENDED:
        std::cout << "Button Save clicked" << std::endl;
        break;
      default:
        break;
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