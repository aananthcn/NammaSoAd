# NammaSoAd
This project realizes AUTOSAR_SWS_SocketAdaptor.pdf. The context can be understood better by looking at the picture below

![image](https://user-images.githubusercontent.com/4141930/216835243-5fc53479-84ae-434c-b870-9dea4618d364.png)

The SoAd enables PDU-based communication via the TCP/IP network. For the abstraction of the TCP/IP
communication SoAd defines socket connections. A SoAd socket connection specifies a connection
between a local socket (i.e. local ip:port) and a remote socket (i.e. remote ip:port), as well as
connection parameters like transport protocol, usage of the SoAd PDU Header, buffer requirements,
connection setup, transport protocol related parameters and so on.
