﻿#ifndef MULTISENDFRAME_H_HEADER_INCLUDED_B97E4E52
#define MULTISENDFRAME_H_HEADER_INCLUDED_B97E4E52
#include "adsStd.h"
#include "SendFrame.h"

/******************************************************************************

    Copyright (c) 2007, AUTEL Ltd,.Co
  
    All rights reserved.

    文件名称：MultiSendFrame.h MultiSendFrame.cpp

    档 标 识：《MaxScan详细设计说明书》

    摘    要：处理并存贮多个发送帧
            
    用途：
    

    历史记录：
    ---------------------------------------------------------------------------
     时     间    作者    版本号      操    作    内    容
    ---------------------------------------------------------------------------
     2007.6.27    王长喜  1.0         创建此类。

*******************************************************************************/

class CMultiSendFrame
{
  public:
	  CSendFrame GetAt(W_I16 iPosition) const;
    /*-----------------------------------------------------------------------------
      功    能：取得发送帧数量
      参数说明：无
      返 回 值：无
      说    明：无
    -----------------------------------------------------------------------------*/
    W_I16 GetSize() const;

    /*-----------------------------------------------------------------------------
      功    能：清空发送帧 
      参数说明：无
      返 回 值：无
      说    明：无
    -----------------------------------------------------------------------------*/
    void Clear();

    /*-----------------------------------------------------------------------------
      功    能：添加发送帧 
      参数说明：CSendFrame SendFrame -- 发送帧
      返 回 值：错误代码
      说    明：无
    -----------------------------------------------------------------------------*/
    W_ErrorCode Add(CSendFrame SendFrame);

    /*-----------------------------------------------------------------------------
      功    能：取得发送帧 
      参数说明：W_I16 iPosition -- 发送帧序号
      返 回 值：发送帧的引用
      说    明：无
    -----------------------------------------------------------------------------*/
    CSendFrame& operator[](W_I16 iPosition);

    /*-----------------------------------------------------------------------------
      功    能：赋值 
      参数说明：const CMultiSendFrame& right -- 多发送帧
      返 回 值：无
      说    明：无
    -----------------------------------------------------------------------------*/
    void operator=(const CMultiSendFrame& right);

    CMultiSendFrame();
    CMultiSendFrame(const CMultiSendFrame& right);
    virtual ~CMultiSendFrame();


protected:
    vector <CSendFrame> m_MultiSendFrame;
};



#endif /* MULTISENDFRAME_H_HEADER_INCLUDED_B97E4E52 */