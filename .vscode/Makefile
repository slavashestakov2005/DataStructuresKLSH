SRC = src
OBJ = build_cpp/obj
GPP = g++ -Wall -std=c++20

run: $(OBJ)/main.o $(OBJ)/frac.o
	$(GPP) -o build_cpp/run $(OBJ)/main.o $(OBJ)/frac.o
$(OBJ)/main.o: main.cpp
	$(GPP) -c -o $(OBJ)/main.o $(SRC)/main.cpp
$(OBJ)/frac.o: examples/frac.cpp
	$(GPP) -c -o $(OBJ)/frac.o $(SRC)/examples/frac.cpp
