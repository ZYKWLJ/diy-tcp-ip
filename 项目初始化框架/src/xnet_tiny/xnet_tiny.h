﻿/**
 * 用1500行代码从0开始实现TCP/IP协议栈+WEB服务器
 *
 * 本源码旨在用最简单、最易懂的方式帮助你快速地了解TCP/IP以及HTTP工作原理的主要核心知识点。
 * 所有代码经过精心简化设计，避免使用任何复杂的数据结构和算法，避免实现其它无关紧要的细节。
 *
 * 本源码配套高清的视频教程，免费提供下载！具体的下载网址请见下面。
 * 视频中的PPT暂时提供下载，但配套了学习指南，请访问下面的网址。
 *
 * 作者：李述铜
 * 网址: http://01ketang.cc/tcpip
 * QQ群1：78034806   QQ群2：1063238091 （加群时请注明：tcpip），免费提供关于该源码的支持和问题解答。
 * 微信公众号：请搜索 01课堂
 *
 * 版权声明：源码仅供学习参考，请勿用于商业产品，不保证可靠性。二次开发或其它商用前请联系作者。
 * 注：
 * 1.源码不断升级中，该版本可能非最新版。如需获取最新版，请访问上述网址获取最新版本的代码
 * 2.1500行代码指未包含注释的代码。
 *
 * 如果你在学习本课程之后，对深入研究TCP/IP感兴趣，欢迎关注我的后续课程。我将开发出一套更加深入
 * 详解TCP/IP的课程。采用多线程的方式，实现更完善的功能，包含但不限于
 * 1. IP层的分片与重组
 * 2. Ping功能的实现
 * 3. TCP的流量控制等
 * 4. 基于UDP的TFTP服务器实现
 * 5. DNS域名接触
 * 6. DHCP动态地址获取
 * 7. HTTP服务器
 * ..... 更多功能开发中...........
 * 如果你有兴趣的话，欢迎关注。
 */


#ifndef XNET_TINY_H
#define XNET_TINY_H
#include <cstdint>

#define XENT_CFG_PACKET_MAX_SIZE		1516		//收发数据包的最大大小


//这是定义包结构的结构体
typedef struct _xnet_packet_t {
	uint16_t size;//包的数据大小
	uint8_t* data;//包的数据的起始地址
	uint8_t payload[XENT_CFG_PACKET_MAX_SIZE];//最大负载数据量
}xnet_packet_t;

xnet_packet_t* xnet_alloc_for_send(uint16_t data_size);//数据包的发送函数
xnet_packet_t* xnet_alloc_for_read(uint16_t data_size);//数据包的接受函数

void xnet_init(void);//数据包的初始化函数
void xnet_poll(void);//数据包的拉取函数

#endif // XNET_TINY_H

