PROJECT := polyfit
OBJS := main.o polyfit.o
CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c99
LDLIBS := -lm

.PHONY: all
all: $(PROJECT)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(PROJECT)

$(PROJECT): $(OBJS)
	$(LINK.o) $^ $(LDLIBS) -o $@

