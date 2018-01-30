main: bin/obj/framebuffer.o bin/obj/line.o bin/obj/main.o
	@echo "Linking ..."
	@g++ bin/obj/framebuffer.o bin/obj/line.o bin/obj/main.o -o main

bin/obj/framebuffer.o: src/framebuffer.cpp src/framebuffer.h
	@echo "Compiling framebuffer.cpp ..."
	@g++ -c src/framebuffer.cpp -o bin/obj/framebuffer.o 

bin/obj/line.o: src/line.cpp src/line.h
	@echo "Compiling line.cpp ..."
	@g++ -c src/line.cpp -o bin/obj/line.o 

bin/obj/main.o: src/main.cpp src/framebuffer.h src/line.h
	@echo "Compiling main.cpp ..."
	@g++ -c src/main.cpp -o bin/obj/main.o 

.PHONY: clean

clean:
	@echo "Removing object files ..."
	@rm -rf bin/obj
	@mkdir bin/obj

	@echo "Removing executable ..."
	@rm -rf main