# paths
INCLUDE = ../../include

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Αρχεία .o
OBJS = assert.o 

# Το εκτελέσιμο πρόγραμμα
EXEC = assert

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS = 

#Το πρόγραμμα valgrind
VLGR = valgrind 

$(EXEC): $(OBJS)
	gcc $(OBJS) -o $(EXEC)


clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS) 

$(VLGR): $(EXEC)
	$(VLGR) ./$(EXEC) $(ARGS) 