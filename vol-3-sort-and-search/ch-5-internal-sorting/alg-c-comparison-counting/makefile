CC = gcc
IDIR = .
CFLAGS = -Wall -I$(IDIR)
DEPS = alg_c_comparison_counting.c comparison_counting.c
OBJ = comp_count

$(OBJ): $(DEPS)
	$(CC) $(DEPS) -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)