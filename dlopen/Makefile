CC= g++
CFLAGS= -Wl,-rpath,. -O0 -g3

all: main libfoo.so libpreload.so libpreload2.so

main: main.c
	$(CC) $(CFLAGS)  $^ -o $@ -ldl

libfoo.so: lib.c libnormal.so
	$(CC) $(CFLAGS) $^ -shared -fPIC -o $@

libpreload.so: preload.c
	$(CC) $(CFLAGS) $^ -shared -fPIC -o $@

libpreload2.so: preload2.c
	$(CC) $(CFLAGS) $^ -shared -fPIC -o $@

libnormal.so: test.c
	$(CC) $(CFLAGS) $^ -shared -fPIC -o $@

clean:
	rm -rf main libfoo.so libpreload.so libnormal.so

.PHONY: clean
