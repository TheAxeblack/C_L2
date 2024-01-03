TARGET = chomp

##########################################################"

CFLAGS = -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
LDLIBS = `pkg-config --libs MLV`

all: $(TARGET)

clean:
	-rm -rf $(TARGET)