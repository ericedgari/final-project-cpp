##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=finalproject
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/yowen/Documents/C++
ProjectPath            :=C:/Users/yowen/Documents/C++/finalproject
IntermediateDirectory  :=../build-$(ConfigurationName)/finalproject
OutDir                 :=../build-$(ConfigurationName)/finalproject
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=yowen
Date                   :=20/05/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw-w64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/mingw64/bin/g++.exe -shared -fPIC
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
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/mingw64/bin/ar.exe rcu
CXX      := C:/mingw-w64/mingw64/bin/g++.exe
CC       := C:/mingw-w64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/finalproject/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/finalproject/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\finalproject" mkdir "..\build-$(ConfigurationName)\finalproject"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\finalproject" mkdir "..\build-$(ConfigurationName)\finalproject"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/finalproject/.d:
	@if not exist "..\build-$(ConfigurationName)\finalproject" mkdir "..\build-$(ConfigurationName)\finalproject"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/finalproject/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/finalproject/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/yowen/Documents/C++/finalproject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/finalproject/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/finalproject/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/finalproject/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/finalproject/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/finalproject/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/finalproject//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


