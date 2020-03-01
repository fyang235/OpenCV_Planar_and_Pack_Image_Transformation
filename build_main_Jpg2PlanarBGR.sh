g++ ./src/main_Jpg2PlanarBGR.cpp  -o Jpg2PlanarBGR -Wall \
-I /home/yang/Documents/APP/opencv/opencvlib/include \
-L /home/yang/Documents/APP/opencv/opencvlib/lib \
-l opencv_world \

# or easier:
# g++ ./src/main_Jpg2PlanarBGR.cpp  -o main_Jpg2PlanarBGR `pkg-config --libs --cflags opencv` -Wall

