FLAGS = -O2 -Wall -Wextra -Wunreachable-code -pedantic

.PHONY: all test clean run_tests
.DEFAULT: all

all: structures test

structures:
	$(MAKE) -C src all

test:
	$(MAKE) -C test all

run_tests:
	$(MAKE) -C test run

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean
