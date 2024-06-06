TARGET:=main
SRC_DIR:=src
OBJ_DIR:=build/obj
BUILD_DIR:=build/debug

CC:=g++
COMPILE_FLAGS:=`pkg-config sdl3 --cflags`-g -std=c++11
LINKER_FLAGS:=`pkg-config --cflags --libs sdl3` -Llib -Iinclude

SOURCE_FILES:=$(wildcard $(SRC_DIR)/*.cpp)
OBJECT_FILES:=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE_FILES))

all: run

#Runs the program
run: $(TARGET)
	./$(BUILD_DIR)/$(TARGET) 3 pong.rom

#Linking step
$(TARGET): $(OBJECT_FILES)
	$(CC) $(LINKER_FLAGS) -o $(BUILD_DIR)/$@ $^

#Compile step
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(COMPILE_FLAGS) -c -o $@ $<
