executable:=laboratorio1

tmp:=./tmp
src:=./src

#objects:=$(tmp)/saludo.o
#sources:=$(src)/saludo.cc

cxx:=g++

includes:=-I./include 


main: $(objects)
	$(cxx) $(includes) $(objects) -o laboratorio1 $(executable).cpp 

$(tmp)/%.o: $(src)/%.cc 
	test -d $(tmp) || mkdir $(tmp)
	$(cxx) $(includes) -c -o $(tmp)/$(*).o $(src)/$*.cc

clean:
	rm -rf $(tmp);
	rm -f $(executable);
