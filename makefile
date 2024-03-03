#
# Created on Sun Mar 03 2024 12:05:01 PM
#
# The MIT License (MIT)
# Copyright (c) 2024 Aananth C N
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software
# and associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial
# portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
# TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
include ${CAR_OS_PATH}/path_defs.mk


INCDIRS  += -I ${CAR_OS_INC_PATH}/autosar \
	    -I ${CAR_OS_INC_PATH}/car_os \
	    -I ${CAR_OS_BOARDSOC_PATH} \
	    -I ${ETH_PATH}/api \
	    -I ${TCPIP_PATH}/api \
	    -I ${TCPIP_PATH}/cfg \
	    -I ${TCPIP_PATH}/src \
	    -I ${SOAD_PATH}/api \
	    -I ${SOAD_PATH}/cfg \
	    -I ${OS_PATH}/include


$(info  )
$(info compiling SoAd source files)


SOAD_OBJS := \
	${SOAD_PATH}/cfg/SoAd_cfg.o \
	${SOAD_PATH}/src/SoAd.o


TARGET 	:= libSoAd.a

# include c_l_flags.mk to add more definitions specific to micro-controller
include ${CAR_OS_PATH}/c_l_flags.mk


%.o: %.c
	$(CC) -c ${CFLAGS} ${INCDIRS} $< -o $@


all: $(TARGET)

LIB_OBJS := $(SOAD_OBJS)

$(TARGET): $(LIB_OBJS)
	$(AR) -rcs ${TARGET} ${LIB_OBJS}


clean:
	$(RM) $(LIB_OBJS) $(TARGET)
