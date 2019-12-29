##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OpenGLProject
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject
ProjectPath            :=/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject
IntermediateDirectory  :=./build-$(ConfigurationName)/
OutDir                 :=./build-$(ConfigurationName)/
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Piotrek
Date                   :=29/12/19
CodeLitePath           :=/home/piotrek/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -lGL -lX11 -lpthread -lXrandr -lXi -ldl
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../../include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glfw3 
ArLibs                 :=  "libglfw3.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../../lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -std=c++14 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=./build-$(ConfigurationName)//main.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//glad.c$(ObjectSuffix) ./build-$(ConfigurationName)//classes_Camera.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//classes_Texture.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//classes_Box.cpp$(ObjectSuffix) ./build-$(ConfigurationName)//classes_Shader.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ./build-$(ConfigurationName)//.d $(Objects) 
	@mkdir -p "./build-$(ConfigurationName)/"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "./build-$(ConfigurationName)/"
	@mkdir -p ""./build-$(ConfigurationName)/bin""

./build-$(ConfigurationName)//.d:
	@mkdir -p "./build-$(ConfigurationName)/"

PreBuild:


##
## Objects
##
./build-$(ConfigurationName)//main.cpp$(ObjectSuffix): main.cpp ./build-$(ConfigurationName)//main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//main.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//main.cpp$(DependSuffix) -MM main.cpp

./build-$(ConfigurationName)//main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//main.cpp$(PreprocessSuffix) main.cpp

./build-$(ConfigurationName)//glad.c$(ObjectSuffix): glad.c ./build-$(ConfigurationName)//glad.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject/glad.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/glad.c$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//glad.c$(DependSuffix): glad.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//glad.c$(ObjectSuffix) -MF./build-$(ConfigurationName)//glad.c$(DependSuffix) -MM glad.c

./build-$(ConfigurationName)//glad.c$(PreprocessSuffix): glad.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//glad.c$(PreprocessSuffix) glad.c

./build-$(ConfigurationName)//classes_Camera.cpp$(ObjectSuffix): classes/Camera.cpp ./build-$(ConfigurationName)//classes_Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject/classes/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/classes_Camera.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//classes_Camera.cpp$(DependSuffix): classes/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//classes_Camera.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//classes_Camera.cpp$(DependSuffix) -MM classes/Camera.cpp

./build-$(ConfigurationName)//classes_Camera.cpp$(PreprocessSuffix): classes/Camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//classes_Camera.cpp$(PreprocessSuffix) classes/Camera.cpp

./build-$(ConfigurationName)//classes_Texture.cpp$(ObjectSuffix): classes/Texture.cpp ./build-$(ConfigurationName)//classes_Texture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject/classes/Texture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/classes_Texture.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//classes_Texture.cpp$(DependSuffix): classes/Texture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//classes_Texture.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//classes_Texture.cpp$(DependSuffix) -MM classes/Texture.cpp

./build-$(ConfigurationName)//classes_Texture.cpp$(PreprocessSuffix): classes/Texture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//classes_Texture.cpp$(PreprocessSuffix) classes/Texture.cpp

./build-$(ConfigurationName)//classes_Box.cpp$(ObjectSuffix): classes/Box.cpp ./build-$(ConfigurationName)//classes_Box.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject/classes/Box.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/classes_Box.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//classes_Box.cpp$(DependSuffix): classes/Box.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//classes_Box.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//classes_Box.cpp$(DependSuffix) -MM classes/Box.cpp

./build-$(ConfigurationName)//classes_Box.cpp$(PreprocessSuffix): classes/Box.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//classes_Box.cpp$(PreprocessSuffix) classes/Box.cpp

./build-$(ConfigurationName)//classes_Shader.cpp$(ObjectSuffix): classes/Shader.cpp ./build-$(ConfigurationName)//classes_Shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/piotrek/Documents/Coding/OpenGL/projects/OpenGLProject/classes/Shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/classes_Shader.cpp$(ObjectSuffix) $(IncludePath)
./build-$(ConfigurationName)//classes_Shader.cpp$(DependSuffix): classes/Shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT./build-$(ConfigurationName)//classes_Shader.cpp$(ObjectSuffix) -MF./build-$(ConfigurationName)//classes_Shader.cpp$(DependSuffix) -MM classes/Shader.cpp

./build-$(ConfigurationName)//classes_Shader.cpp$(PreprocessSuffix): classes/Shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ./build-$(ConfigurationName)//classes_Shader.cpp$(PreprocessSuffix) classes/Shader.cpp


-include ./build-$(ConfigurationName)///*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


