# paths
MODULES= ../../Number
INCLUDE= ../../include

# Compile options. Το -I<dir> χρειάζεται για να βρει ο gcc τα αρχεία 
CFLAGS= -Wall -Werror -g -I$(INCLUDE)

# Αρχεία .o, εκτελέσιμο πρόγραμμα και παράμετροι
OBJS= number.o	numb.o
EXEC= number
ARGS=

$(EXEC):$(OBJS) 
	gcc $(OBJS) -o $(EXEC)
   
clean:  
	rm -f $(OBJS)$(EXEC)
    
run: $(EXEC)   
	./$(EXEC)$(ARGS)