g++ -std=c++14 -pthread -lm -O3 ${1}.cpp -o ${1}
./${1} < ${1}.txt