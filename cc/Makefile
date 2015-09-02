
SRCS := $(wildcard src/*.cc)
OBJS := $(SRCS:.cc=.o)
CXXFLAGS := -O3 -std=c++0x -lstdc++ -LC:\Mingw64\lib

TARGET := ballclock.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	# rm -f $(OBJS) $(TARGET) $(TESTOBJS)
