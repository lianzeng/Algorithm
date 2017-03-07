TARGET:=ut_bst


GTEST_DIR:=../../googletest/googletest
libgtestpath=$(GTEST_DIR)/make
GXX:=g++ -std=c++11

SRC_DIRS:=.
C_SRCS:=$(foreach d, $(SRC_DIRS), $(wildcard $d/*.c))
CXX_SRCS:=$(foreach d,$(SRC_DIRS), $(wildcard $d/*.cpp))
C_OBJS:=$(C_SRCS:.c=.o)
CXX_OBJS:=$(CXX_SRCS:.cpp=.o)

INCDIR:=-I$(GTEST_DIR)/include -I . 
LDFLAGS:=-L$(libgtestpath) -lgtest -lstdc++ -lpthread

$(TARGET) : $(CXX_OBJS) $(C_OBJS)	
	make libgtest
	$(GXX) -o $@ $^ $(LDFLAGS)
	@echo $(TARGET) ok! pls run using ./$(TARGET) 

$(C_OBJS) : %.o : %.c
	$(GXX) -g -c -o $@ $^ $(INCDIR)

$(CXX_OBJS) : %.o : %.cpp	
	$(GXX) -g -c -o $@ $^ $(INCDIR)

libgtest:
	cd $(libgtestpath);make libgtest.a;cd -;

clean:
	-rm $(C_OBJS) $(CXX_OBJS) $(TARGET)

