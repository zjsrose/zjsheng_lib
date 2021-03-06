﻿#ifndef DIAGNOSISFRAME_H_HEADER_INCLUDED_B980A093
#define DIAGNOSISFRAME_H_HEADER_INCLUDED_B980A093

/******************************************************************************

    Copyright (c) 2007, AUTEL Ltd,.Co
  
    All rights reserved.

    文件名称：DiagnosisFrame.h DiagnosisFrame.cpp

    档 标 识：《MaxScan详细设计说明书》

    摘    要：诊断程序框架
            
    用途：
    

    历史记录：
    ---------------------------------------------------------------------------
     时     间    作者    版本号      操    作    内    容
    ---------------------------------------------------------------------------
     2007.6.25    王长喜  1.0         创建此类。

*******************************************************************************/

#include "adsStd.h"

class CDiagnosisFrame
{
  public:
    /*-----------------------------------------------------------------------------
      功    能：为诊断程序执行做好各种准备工作
      参数说明：无
      返 回 值：错误代码
      说    明：实现如下工作：
                1、初始化显示接口；
                2、初始化通信接口；
                3、判断是否被合法受权执行；
                4、创建车系实例，调入口函数；
                5、释放显示所需资源
                6、释放ECU通信所需资源
    -----------------------------------------------------------------------------*/
    W_ErrorCode InitInstance();
    
    CDiagnosisFrame();
    virtual ~CDiagnosisFrame();
};



#endif /* DIAGNOSISFRAME_H_HEADER_INCLUDED_B980A093 */
