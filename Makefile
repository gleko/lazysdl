#OBJS specifies which files to compile as part of the project
OBJS = SDLApp/src/Main/main.cc SDLApp/src/Display/Display.cc SDLApp/src/Display/Texture.cc

#IDIR specifies the include directory
IDIR = -ISDLApp/include

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -std=c++11 use C++11 standard for compile
COMPILER_FLAGS = -w -std=c++11

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/SDLApp

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(IDIR) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
