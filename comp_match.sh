g++ -c input_comands.cpp -o input_comands.o
g++ -c tryangle_match.cpp -o tryangle_match.o
g++ -c chenge_massiv.cpp -o chenge_massiv.o
g++ -c Cheks.cpp -o Cheks.o
g++ tryangle_match.o input_comands.o Cheks.o chenge_massiv.o -o tryangle_match
./tryangle_match
