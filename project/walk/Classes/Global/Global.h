#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#pragma once

namespace jiangweigithub {

#define TALKLINEWIDTH 111
#define PREFACEWIDTH 99
#define PREFACESPEED 2
#define LITTLETALKFRAMEEDGE 2
#define LITTLETALKFRAMEARROWWIDTH 10
#define LITTLETALKFRAMEARROWHEIGHT 10

enum littleTalkFrameArrowDirection
{
  LEFT = 1,
  RIGHT = 2,
};

enum CHAPTER
{
  // >>>>>>>>>>>>>>>>>
  HOME =    10000,
  MYROOM =  10100,

  // >>>>>>>>>>>>>>>>>
  TOWN = 20000,

  // >>>>>>>>>>>>>>>>>
  FIELD = 30000,

  // >>>>>>>>>>>>>>>>>
  FOREST = 40000,

  // >>>>>>>>>>>>>>>>>
  CASTLE = 50000,
};

}

#endif // __GLOBAL_H__