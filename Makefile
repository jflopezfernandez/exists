
vpath %.c src

RM     := rm -f

CPPFLAGS := $(CPPFLAGS) -I include

OBJS   := $(patsubst %.c,%.o,$(notdir $(wildcard src/*.c)))

TARGET := exists

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.c) -o $@ $^ $(LIBS)

%.o: %.c
	$(COMPILE.c) -o $@ $^

.PHONY: docs
docs:
	doxygen doc/Doxyfile

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
