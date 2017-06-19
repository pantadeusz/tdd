# This are internal config for Make
VER=$(shell hg head | head -n 1 | awk -F'[: \t]+' '{print $$2}')
VER_MAJOR=0
VER_MINOR=0
CPPFLAGS= -fPIC -pthread -std=c++0x -O2 -I./include -fopenmp -I./thirdparty/json -I./thirdparty/catch
CLIBS= -std=c++0x -fopenmp -ldl -rdynamic


##################  CONFIG #################
#

BASEOBJS := build/filedb.o

TESTOBJS := build/test/unit-filedb.o build/unit.o

#
################## ENDCONDIF ###############


all: $(BASEOBJS)
	
unittests: $(BASEOBJS) $(TESTOBJS)
	g++ -O2 $^ -o $@ $(CLIBS)

test: unittests
	./unittests
#	./unittests -r junit

build/unit.o: src/unit.cpp
	gcc -c $(CPPFLAGS) $< -o $@

build/%.o : src/%.cpp
	@echo $<
	gcc -c $(CPPFLAGS) $< -o $@

build/test/%.o : src/test/%.cpp
	@echo $<
	gcc -c $(CPPFLAGS) $< -o $@

%.o : %.cpp
	gcc -c $(CPPFLAGS) $<

clean:
	rm -f $(APPNAME) $(OBJS) build/*.o build/test/*.o unittests
