/*
 * Created on Sun Feb 25 2024 6:59:41 PM
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

#include <SoAd.h>
#include <SoAd_cfg.h>
#include <tcpip_extensions.h>



struct SocketControl {
        SoAd_SoConIdType sock_id;
        SoAd_SoConModeType sock_mode;
        PduIdType tx_pdu_id;
        TcpIp_DomainType ip_version;
        TcpIp_ProtocolType protocol;
        TcpIp_StateType tcp_state;
};

struct SocketControl SockCtrlDataBlock[MAX_TOTAL_SOCKET_CONNS];



// Returns socket connection index related to the specified TxPduId.
Std_ReturnType SoAd_GetSoConId(PduIdType TxPduId, SoAd_SoConIdType* SoConIdPtr) {
        Std_ReturnType retval = E_OK;


        return retval;
}



// This service opens the socket connection specified by SoConId.
Std_ReturnType SoAd_OpenSoCon(SoAd_SoConIdType SoConId) {
        Std_ReturnType retval = E_OK;


        return retval;
}



// This service closes the socket connection specified by SoConId.
Std_ReturnType SoAd_CloseSoCon(SoAd_SoConIdType SoConId, boolean abort) {
        Std_ReturnType retval = E_OK;


        return retval;
}



// Returns current state of the socket connection specified by SoConId.
void SoAd_GetSoConMode(SoAd_SoConIdType SoConId, SoAd_SoConModeType* ModePtr) {
}



// By this API service the local IP address assignment which shall be used for the socket
// connection specified by SoConId is initiated.
Std_ReturnType SoAd_RequestIpAddrAssignment(SoAd_SoConIdType SoConId, TcpIp_IpAddrAssignmentType Type,
	const TcpIp_SockAddrType* LocalIpAddrPtr, uint8 Netmask, const TcpIp_SockAddrType* DefaultRouterPtr)
{
        Std_ReturnType retval = E_OK;


        return retval;
}



// By this API service the local IP address assignment used for the socket connection specified by
// SoConId is released.
Std_ReturnType SoAd_ReleaseIpAddrAssignment(SoAd_SoConIdType SoConId) {
        Std_ReturnType retval = E_OK;


        return retval;
}