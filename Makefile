APPLICATION=sus

all: compile run

# another thing to accept args from makefile (this rule avoid complains for random make commands)
%:
	@:

compile:
	mkdir -p build &&\
	cd build &&\
	echo "\n\033[1;33m█ Generating makefiles...\033[0m\n" &&\
	cmake .. &&\
	echo "\n\033[1;93m█ Compiling...\033[0m\n" &&\
	cmake --build .

run:
	@echo "\n\033[1;32m█ Running...\033[0m\n\n" &&\
	./build/$(APPLICATION)