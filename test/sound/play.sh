#!/bin/sh
[ "$#" -eq 0 ] && {
echo "Usage: $0 filename"
exit
}
ORDER=`file $1 | cut -d' ' -f3`
BITS=`file $1 | cut -d' ' -f9`
CHANNEL=`file $1 | cut -d' ' -f11`
RATE=`file $1 | cut -d' ' -f12`
#channel
if [ "$CHANNEL" == "stereo" ]; then
CHANNEL=2
else
CHANNEL=1
fi
#platform-byte-order
if [ "$ORDER" == "(little-endian)" ]; then
ORDER=1
else
ORDER=2
fi
echo "Playing...$(file $1)"
./playsound $1 $RATE $BITS $CHANNEL $ORDER
