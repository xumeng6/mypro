OBJ=input.o primer.o


input.o:input.cpp
	g++ -c -fPIC input.cpp
primer.o:primer.cpp
	g++ -c -fPIC primer.cpp
libdemo.so:$(OBJ)
	g++ -shared -fPIC -olibdemo.so $(OBJ)
demo:demo.cpp libdemo.so
	g++ demo.cpp -ldemo -L. -odemo
clean:
	rm -f *.o demo *.so *.a main
