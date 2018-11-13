
sudo apt-get install cmake
sudo apt-get install xorg-dev

Obs.: fazer dos2unix no arquivo dllmain.cpp

Baixar o projeto

cd ${PROJECT_DIR}
mkdir build
cd build
cmake ..
cmake --build .
./PixelEffect