 gcc -Wall -g  tubes.c   -o test -lwiringPi -lpthread -D_REENTRANT   $(pkg-config --libs --cflags libmodbus)

# gcc -Wall -g bddtxt.c libbitwiseED.c libreglesregulesED.c gestionaccu.c dallas.c pidbbe.c libmodbusbbe.c testIO.c lcd_i2c.c  -o testIO -lwiringPi -lpthread -D_REENTRANT   $(pkg-config --libs --cflags libmodbus)
