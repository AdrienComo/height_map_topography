CFLAGS = `pkg-config --cflags opencv4`
LIBS = `pkg-config --libs opencv4`

B = bin
O = obj
S = src
FLAGS = -c -Wall

all: $(O) $(B) $(B)/main

$(B)/main: $(O)/GrayscaleConvert.o 
	g++ $(CFLAGS) $(LIBS) $(S)/main.cpp -o $(B)/main $(O)/*.o -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
	
$(O)/GrayscaleConvert.o: 
	g++ $(FLAGS) $(CFLAGS) $(LIBS) $(S)/GrayscaleConvert.cpp -o $(O)/GrayscaleConvert.o 

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)

clean: $(O) $(B)
	rm -rf $(O)
	rm -rf $(B)
