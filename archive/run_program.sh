g++ -c main.cpp -o main.o -std=c++17; \
g++ -c user.cpp -o user.o -std=c++17; \
g++ main.cpp user.cpp -o program -std=c++17; \
./program; \
rm main.o user.o program;