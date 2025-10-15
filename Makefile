main: build/main.o build/Tools.o
	g++ -o build/Simulation build/main.o build/Tools.o

build/main.o: src/main.cpp src/constants.hpp src/Tools.hpp build/
	g++ -c src/main.cpp -o build/main.o

build/Tools.o: src/Tools.cpp src/constants.hpp src/Tools.hpp build/
	g++ -c src/Tools.cpp -o build/Tools.o

build/:		# 需要先创建build/文件夹
	mkdir build

clean: 
	rm build/*.o build/*.so build/Simulation || true

run:
	./build/Simulation
