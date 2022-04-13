CFLAGS := -Wall -g

trash += *.o *~

clean:
	$(RM) $(trash)

.PHONY: clean
