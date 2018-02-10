#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#pragma once

#include "iostream"
#include <sstream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UICheckBox.h"

#include "../../Global/Global.h"
#include "../../Scene/Init/Login.h"
#include "../../Processor/Database/Database.h"

namespace jiangweigithub {
  
  class BackgroundLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getBackgroundLayer();
    virtual bool init();

    CREATE_FUNC(BackgroundLayer);

  private:
    void update(float delta) override;
    void _musicVolumeEvent(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type);
    void _BGMVolumeEvent(cocos2d::Ref *pSender, cocos2d::ui::Slider::EventType type);
    void _selectedSubCheckBoxEvent(cocos2d::Ref* pSender,cocos2d::ui::CheckBox::EventType type);
    void _saveButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type);
    void _resetButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type);
    void _backButtonEvent(cocos2d::Ref* pSender,cocos2d::ui::Widget::TouchEventType type);
    
    cocos2d::ui::Slider* _musicSlider;
    cocos2d::ui::Slider* _bgmSlider;
    cocos2d::ui::CheckBox* _subCheckBox;
    cocos2d::ui::Text* _musicVolumeLabel;
    cocos2d::ui::Text* _bgmVolumeLabel;
    cocos2d::ui::Text* _subLabel;

    int _musicVolume, _bgmVolume, _subtitle;
  };

}

#endif // __BACKGROUND_H__