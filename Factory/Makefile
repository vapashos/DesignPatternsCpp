CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		FactoryDriver.o

LIBS =

TARGET =	FactoryDriver

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
