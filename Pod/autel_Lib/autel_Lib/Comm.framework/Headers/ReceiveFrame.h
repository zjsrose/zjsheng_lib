﻿#ifndef RECEIVEFRAME_H_HEADER_INCLUDED_B97F1E5D
#define RECEIVEFRAME_H_HEADER_INCLUDED_B97F1E5D
#include "Binary.h"

/******************************************************************************

    Copyright (c) 2007, AUTEL Ltd,.Co

    All rights reserved.

    文件名称：ReceiveFrame.h ReceiveFrame.cpp

    档 标 识：《MaxScan详细设计说明书》

    摘    要：处理并存贮接收帧

    用    途：


    历史记录：
    ---------------------------------------------------------------------------
     时     间    作者    版本号      操    作    内    容
    ---------------------------------------------------------------------------
     2007.6.26    王长喜  1.0         创建此类。
     2007.6.29    王长喜  1.0         编写完成代码, 并在PC下编译通过
     2007.10.24   王长喜  1.0         重写全部代码--将数据存贮方式由vector改成
                                      自定义格式, 以提高运行效率及内存空间利用
                                      并解决测试中发现的修改代码段的问题

*******************************************************************************/
class CReceiveFrame
{
  public:
    CBinary GetAt(W_I16 iPosition) const;
    /*-----------------------------------------------------------------------------
      功    能：取得ECU回复的第一帧数据
      参数说明：无
      返 回 值：一帧数据
      说    明：如ECU无应答，则返回空二进制数据
    -----------------------------------------------------------------------------*/
    CBinary GetFirst() const;

    /*-----------------------------------------------------------------------------
      功    能：添加接收帧内容
      参数说明：CBinary bin -- 一帧ECU数据
      返 回 值：实际加入的数量
      说    明：无
    -----------------------------------------------------------------------------*/
    W_I16 Add(CBinary bin);
    W_I16 Add(const CReceiveFrame& right);

    /*-----------------------------------------------------------------------------
      功    能：删除某一接收帧
      参数说明：W_I16 iIndex 接收帧序号
      返 回 值：错误代码
      说    明：无
    -----------------------------------------------------------------------------*/
    W_ErrorCode Delete(W_I16 iIndex);

    /*-----------------------------------------------------------------------------
      功    能：清空接收帧内容
      参数说明：无
      返 回 值：无
      说    明：无
    -----------------------------------------------------------------------------*/
    void Clear();

    W_I16 FreeExtra();

    /*-----------------------------------------------------------------------------
      功    能：取得接收帧数
      参数说明：无
      返 回 值：接收帧中所含帧数量
      说    明：无
    -----------------------------------------------------------------------------*/
    W_I16 GetSize() const;

    W_I16 SetSize(W_I16 iNewSize);

    /*-----------------------------------------------------------------------------
      功    能：取得一帧数数据
      参数说明：帧序号，0为起始
      返 回 值：帧内容的引用
      说    明：无
    -----------------------------------------------------------------------------*/
    CBinary& operator[](W_I16 iSequence) const;

    /*-----------------------------------------------------------------------------
      功    能：赋值
      参数说明：无
      返 回 值：无
      说    明：无
    -----------------------------------------------------------------------------*/
    void operator = (const CReceiveFrame& right);

    void operator += (const CReceiveFrame& right);
   /*-----------------------------------------------------------------------------
      功    能：构造函数
      参数说明：无
      返 回 值：无
      说    明：无
    -----------------------------------------------------------------------------*/
    CReceiveFrame();

    CReceiveFrame(const CReceiveFrame& right);


    virtual ~CReceiveFrame();

  private:
    // 接收帧内容串
    //
    // 格式 ::= <接收帧数>+[<帧数据>+...]
    //      <接收帧数> ::= <1字节长度>
    //      <帧数据> ::= <数据长度>+<数据内容>
    //          <数据长度> ::= <1个字节长度>|<3个字节长度>
    //              <1个字节长度> ::= 一个小于等于254的数值
    //              <3个字节长度> ::= 0xFF + 长度高位字节 + 长度低位字节
    // CBinary m_binReceiveString;
    //vector <CBinary> m_aContain;

    // 分配数量
    W_I16 m_iAllocNumber;

    // 实际帧数
    W_I16 m_iFrameNumber;

    // 缓冲区
    CBinary* m_pContain;
};

#endif /* RECEIVEFRAME_H_HEADER_INCLUDED_B97F1E5D */

