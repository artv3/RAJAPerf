mkdir build-knl && cd build-knl && cmake -DCMAKE_CXX_COMPILER=icpc -DCMAKE_C_COMPILER=icc   -DCMAKE_CXX_FLAGS=' -std=c++11 -qopenmp -O3 -xMIC-AVX512 -qopt-report=4 -qopt-report-phase vec' ../
make -j
