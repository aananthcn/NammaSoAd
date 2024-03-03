/*
 * Created on Fri Feb 23 2024 10:23:11 AM
 *
 * The MIT License (MIT)
 * Copyright (c) 2024 Aananth C N
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef CAR_OS_SOAD_H
#define CAR_OS_SOAD_H

#include <Platform_Types.h>
#include <Std_Types.h>

#include <ComStack_Types.h>
#include <TcpIp.h>
#include <SoAd_cfg.h>


typedef uint16_t SoAd_SoConIdType;
typedef uint16_t SoAd_RoutingGroupIdType;

#define SOAD_MEAS_DROP_TCP	0x01
#define SOAD_MEAS_DROP_UDP	0x02
#define SOAD_MEAS_ALL		0xff
typedef uint8_t SoAd_MeasurementIdxType;

typedef enum {
	SOAD_SOCON_OFFLINE,
	SOAD_SOCON_RECONNECT,
	SOAD_SOCON_ONLINE
} SoAd_SoConModeType; 




// General functions
void SoAd_GetVersionInfo(Std_VersionInfoType* versioninfo);
void SoAd_Init(const SoAd_ConfigType* SoAdConfigPtr);

// Normal operations
Std_ReturnType SoAd_IfTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);
Std_ReturnType SoAd_IfRoutingGroupTransmit(SoAd_RoutingGroupIdType id);
Std_ReturnType SoAd_IfSpecificRoutingGroupTransmit(SoAd_RoutingGroupIdType id, SoAd_SoConIdType SoConId);
Std_ReturnType SoAd_TpTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);

// Transmit/Receive Cancelation API
Std_ReturnType SoAd_TpCancelTransmit(PduIdType TxPduId);
Std_ReturnType SoAd_TpCancelReceive(PduIdType RxPduId);

Std_ReturnType SoAd_TpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);


// Information and Control API
Std_ReturnType SoAd_GetSoConId(PduIdType TxPduId, SoAd_SoConIdType* SoConIdPtr);
Std_ReturnType SoAd_OpenSoCon(SoAd_SoConIdType SoConId);
Std_ReturnType SoAd_CloseSoCon(SoAd_SoConIdType SoConId, boolean abort);

void SoAd_GetSoConMode(SoAd_SoConIdType SoConId, SoAd_SoConModeType* ModePtr);
Std_ReturnType SoAd_RequestIpAddrAssignment(SoAd_SoConIdType SoConId, TcpIp_IpAddrAssignmentType Type,
	const TcpIp_SockAddrType* LocalIpAddrPtr, uint8 Netmask, const TcpIp_SockAddrType* DefaultRouterPtr);
Std_ReturnType SoAd_ReleaseIpAddrAssignment(SoAd_SoConIdType SoConId);

Std_ReturnType SoAd_GetLocalAddr(SoAd_SoConIdType SoConId, TcpIp_SockAddrType* LocalAddrPtr, uint8* NetmaskPtr,
	TcpIp_SockAddrType* DefaultRouterPtr);
Std_ReturnType SoAd_GetPhysAddr(SoAd_SoConIdType SoConId, uint8* PhysAddrPtr);
Std_ReturnType SoAd_GetRemoteAddr(SoAd_SoConIdType SoConId, TcpIp_SockAddrType* IpAddrPtr);

Std_ReturnType SoAd_EnableRouting(SoAd_RoutingGroupIdType id);
Std_ReturnType SoAd_EnableSpecificRouting(SoAd_RoutingGroupIdType id, SoAd_SoConIdType SoConId);
Std_ReturnType SoAd_DisableRouting(SoAd_RoutingGroupIdType id);
Std_ReturnType SoAd_DisableSpecificRouting(SoAd_RoutingGroupIdType id, SoAd_SoConIdType SoConId);

Std_ReturnType SoAd_SetRemoteAddr(SoAd_SoConIdType SoConId, const TcpIp_SockAddrType* RemoteAddrPtr);
Std_ReturnType SoAd_SetUniqueRemoteAddr(SoAd_SoConIdType SoConId, const TcpIp_SockAddrType* RemoteAddrPtr,
	SoAd_SoConIdType* AssignedSoConIdPtr);
void SoAd_ReleaseRemoteAddr(SoAd_SoConIdType SoConId);

Std_ReturnType SoAd_ReadDhcpHostNameOption(SoAd_SoConIdType SoConId, uint8* length, uint8* data);
Std_ReturnType SoAd_WriteDhcpHostNameOption(SoAd_SoConIdType SoConId, uint8 length, const uint8* data);

Std_ReturnType SoAd_GetAndResetMeasurementData(SoAd_MeasurementIdxType MeasurementIdx,
	boolean MeasurementResetNeeded, uint32* MeasurementDataPtr);
TcpIp_ReturnType SoAd_IsConnectionReady (SoAd_SoConIdType SoConId,const TcpIp_SockAddrType* RemoteAddrPtr);


// Callback notifications
void SoAd_RxIndication(TcpIp_SocketIdType SocketId, const TcpIp_SockAddrType* RemoteAddrPtr,
	const uint8* BufPtr, uint16 Length);
BufReq_ReturnType SoAd_CopyTxData(TcpIp_SocketIdType SocketId, uint8* BufPtr, uint16 BufLength);
void SoAd_TxConfirmation(TcpIp_SocketIdType SocketId, uint16 Length);
Std_ReturnType SoAd_TcpAccepted(TcpIp_SocketIdType SocketId, TcpIp_SocketIdType SocketIdConnected,
	const TcpIp_SockAddrType* RemoteAddrPtr);
void SoAd_TcpConnected(TcpIp_SocketIdType SocketId);
void SoAd_TcpIpEvent(TcpIp_SocketIdType SocketId, TcpIp_EventType Event);
void SoAd_LocalIpAddrAssignmentChg(TcpIp_LocalAddrIdType IpAddrId, TcpIp_IpAddrStateType State);

// Scheduled functions
void SoAd_MainFunction(void);

#endif