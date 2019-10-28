CC=g++
CFLAGS= -Wall -g3 -O0 -D__ASSERT__ -Wl,--as-needed -D_DEBUG 
# CC=${QNX_HOST}/usr/bin/qcc
# CFLAGS= -Vgcc_ntox86_64 -Wall -g3 -O0 -DOS_QNX #-D_DEBUG #-D__ASSERT__ 
RM=rm -rf
MV=mv
MKDIR=mkdir -p
#TARGET=libSocket.so libPreLoad.so libTestLibrary.so MemCheck demo
TARGET=libPreLoad.so libTestLibrary.so demo
TARGET_DIR=target 

LIBS        := -lm -ldl 
#LIBS_DIR	:= -L${QNX_TARGET}/x86_64/lib -L${QNX_TARGET}/x86_64/usr/lib

all: $(TARGET)

env:
	$(MKDIR) $(TARGET_DIR)

demo: main.cpp
	$(CC) -O3 -g0 -Wl,--as-needed $^ -o $@ -ldl -lpthread -nostdinc++ -std=gnu++11
	#$(MV) $@ $(TARGET_DIR)

libPreLoad.so: PreloadMemory.cpp CMemoryManager.cpp
	$(CC) $(CFLAGS) --shared -fPIC $^ -o $@ $(LIBS_DIR) $(LIBS)
	#$(MV) $@ $(TARGET_DIR)

libTestLibrary.so: TestLibrary.cpp
	$(CC) $(CFLAGS) -shared -fPIC $^ -o $@ $(LIBS_DIR) $(LIBS)
	#$(MV) $@ $(TARGET_DIR)

clean:
	$(RM) $(TARGET) 
	$(RM) libPreLoad.so
	$(RM) core err PreLoad

.PHONY:clean
