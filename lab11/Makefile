#Xavier Briggs
#Makefile lab11
#May 3, 2024

CMP = gcc
MAIN = project
FUNC = projectfunc
EXEC = project

$(EXEC): $(FUNC).o $(MAIN).o 
	$(CMP) $(FUNC).o $(MAIN).o gfx2.o -lX11 -lm -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h 
	$(CMP) -c $(FUNC).c -o $(FUNC).o 

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c -o $(MAIN).o 

clean:
	rm $(EXEC)
	rm project.o
	rm projectfunc.o

