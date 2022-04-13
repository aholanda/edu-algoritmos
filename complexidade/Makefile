main: main.c
	gcc $< -DMAX -DBUSCA -o $@

busca: main.c
	gcc $< -DBUSCA -o $@

max: main.c
	gcc $< -DMAX -o $@

clean:
	$(RM) busca main max
