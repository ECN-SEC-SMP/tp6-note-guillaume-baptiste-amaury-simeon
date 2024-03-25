CXX = clang++

override CXXFLAGS += -g -Wno-everything -stdlib=libc++

TARGET = main.o

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')

HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)



all: $(TARGET)



$(TARGET): $(SRCS) $(HEADERS)

	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"



main-debug: $(SRCS) $(HEADERS)

	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@"



clean:

	rm -f $(TARGET) main-debug
