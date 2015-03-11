CFLAGS = -pipe -W -Wall -Wpointer-arith -Wno-unused-parameter -Wunused-function -Wunused-variable -Wunused-value -DSPM_EXAMPLE -g

all: spm_test
spm_test: spm_test.c spm.c spm_bm.c spm_bs.c spm_bs2bm.c
clean:
	rm -f spm_test
	rm -f *.o

.PHONY: clean
