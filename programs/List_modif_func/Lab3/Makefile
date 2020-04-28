# paths
INCLUDE = ../../include
MISC = ../../misc

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Το αρχείο file ως είσοδος στο πρόγραμμα
#FILE = $(MISC)/words/words-10

# Αρχεία .o
OBJS = toappend.o  lib/k08.a

# Το εκτελέσιμο πρόγραμμα
EXEC = toappend

# Παράμετροι για δοκιμαστική εκτέλεση
ARGS =

# Το αρχείο file ως είσοδος στο πρόγραμμα
FILE = $(MISC)/words/words-100000

#Το πρόγραμμα valgrind
VLGR = valgrind 

$(EXEC): $(OBJS)
	gcc $(OBJS) -o $(EXEC)


clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)  $(ARGS)

$(VLGR): $(EXEC)
	$(VLGR) ./$(EXEC) $(ARGS) 

time: $(EXEC)
	time ./$(EXEC) $(ARGS) 