CC = gcc
IDIR = .
CFLAGS = -Wall -I$(IDIR)
DEPS = test_comp_count.c comparison_count.c
OBJ = test_comp_count

$(OBJ): $(DEPS)
	$(CC) $(DEPS) -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)