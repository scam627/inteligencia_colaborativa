all: main

STD = g++ -std=c++11
EXECUTE = main

main: ./src/clasificacion.hh main.cpp
	@echo "Compiling Programs"
	@$(STD) -o $(EXECUTE) main.cpp

execute: main
	@./$(EXECUTE) < ./test/clasificacion.txt

clean:
	@rm $(EXECUTE)
