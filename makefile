CXX = g++
CXXFLAGS = -Wall
TARGETS = Main.exe Creator.exe Reporter.exe

all: $(TARGETS)

Main.exe: Main.cpp employee.h
	$(CXX) Main.cpp -o Main.exe $(CXXFLAGS)

Creator.exe: Creator.cpp employee.h
	$(CXX) Creator.cpp -o Creator.exe $(CXXFLAGS)

Reporter.exe: Reporter.cpp employee.h
	$(CXX) Reporter.cpp -o Reporter.exe $(CXXFLAGS)

clean:
	del /Q *.exe *.bin *.txt 2>nul || rm -f *.exe *.bin *.txt

run: all
	Main.exe

.PHONY: all clean run